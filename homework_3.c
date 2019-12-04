#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void secondSteb ( int number );                                                //функция генерации графа и выбора действия с ним

int main ( void )
{
  int numNodes = 0;
	printf("Please, enter the number of nodes in the graph (No more 50) :\n");
  scanf (" %d", &numNodes);
  getchar();
  if ( numNodes <= 50 )
    {
      secondSteb ( numNodes );
    }
  else
    {
      printf("Is you immature? Go again!\n");
      return -1;
    }
	return 0;
}

void showing (int** mass, int lenght);                                                                                               //Функция демонстрации матрицы смежности
void extentSort(int *mass, int length);
void menu_acts (void);

void secondSteb ( int number )
{
  int key = 0;

  int** pointer = (int **) malloc( number * sizeof(int*) ); // создания динамиеского двумерного массива
  for (int i = 0; i < number; ++i)
  {
    pointer[i] = (int*) malloc ( number * sizeof(int) );
  }

    for (int i = 0; i < number; i++)
  {
    for (int j = i+1; j < number; j++)
    {
      pointer[i][j] = rand() % 2;
      pointer[j][i] = pointer[i][j];
    }
    pointer[i][i] = 0;
  }

  int nodeDegrees[number];  				//массив степеней вершин графа
  for (int i = 0; i < number; i++)			// указание степеней всех вершин
	{
		nodeDegrees[i] = 0;
		for (int j = 0; j < number; j++)
		{
			if ( pointer [i][j] == 1)
			{
				nodeDegrees[i]++;
			}
		}
	}

  printf("Graph was created.\n What do you want to do with it:\n");
  menu_acts();
  while (key <= 5)
  {
    scanf("%d", &key);
    switch(key)
    {
      case 1:
      showing( pointer, number );
      menu_acts();
      break;

      case 2:
      extentSort( nodeDegrees, number);
      menu_acts();
      break;

      case 3:
      printf("Good luck!\n");
      return;
      break;

      default:
      printf("You didn't enter a number from the list. Go again! \n");
      break;
    }
  }
  return;
}

void showing (int** mass, int lenght)
{
  for (int i = 0; i < lenght; i++)
  {
    for (int j = 0; j < lenght; j++)
    {
     printf("%d ", mass[i][j]);
   }
   printf("\n");
 }
 return;
}

void extentSort(int *mass, int length)
{
	int newElement, location;

	for (int i = 1; i < length; i++)
	{
		newElement = mass[i];
		location = i - 1;
		while(location >= 0 && mass[location] > newElement)
		{
			mass[location+1] = mass[location];
			location = location - 1;
		}
		mass[location+1] = newElement;
	}
	for (int i = 0; i < length; i++)
	{
		printf("%d:%d\n",i,mass[i]);
	}
}

void menu_acts (void)
{
  printf("1: Show the adjacency matrix\n");
  printf("2: Create the mass of node degrees and sort by inserts\n");
  printf("3: Exit\n");
}
