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
void creating (int** mass, int *allNodes, int lastNode);                                                                             //Функция создания текстового файла
void check(int** mass, int *allNodes, int startNode, int lastNode, int *amountLinks);                                                //Функция проверки связности 
void menu_acts (void);   

void secondSteb ( int number )                               
{
  int key = 0;
  int startLinks = 0;
  int *amountLinks = &startLinks;

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

  int firstNodes[number];   //массив вершин графа
  for (int i = 0; i < number; i++)
  {
    firstNodes[i] = 0;
  }

  int secNodes[number];   //2-й массив вершин графа
  for (int i = 0; i < number; i++)
  {
    secNodes[i] = 0;
  }

  printf("Graph was created.\n What do you want to do with it:\n");
  menu_acts();
  while (key <= 4)
  {
    scanf("%d", &key);
    switch(key)
    {
      case 1:
      showing( pointer, number );
      menu_acts();
      break;

      case 2:
      check( pointer, firstNodes, 0, number, amountLinks);
      if ( *amountLinks == (number-1) )                                             //Вывод информации связан ли глаф
      {
        printf("Graph is connectivity\n\n");
      }
      else
      {
        printf("Graph isn't connectivity\n\n");
      }
      menu_acts();
      break;

      case 3:
      creating( pointer, secNodes, number);
      menu_acts();
      break;

      case 4:
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

void check(int** mass, int *allNodes, int startNode, int lastNode, int *amountLinks)
{
  int linkedNode;
  
  allNodes[startNode] = 1;

  for (linkedNode = 0; linkedNode < lastNode; linkedNode++)                  //подсчёт связанных вершин
    if ((mass[startNode][linkedNode] != 0) && (allNodes[linkedNode] == 0)) 
    {
      printf("%d -> %d. Nodes are linked\n", startNode+1,linkedNode+1);
      (*amountLinks)++;
      check(mass, allNodes, linkedNode, lastNode, amountLinks);
    }
}

void checkTwo(int** mass, int *allNodes, int startNode, int lastNode);   //Функция записи в файл связанных вершин

void creating(int** mass, int *allNodes, int lastNode)
{
  FILE *fp;
  char* start = "graph G {";
  char* end = "}";
  char file[] = "graph.txt";

  fp = fopen(file,"w");
  fprintf(fp, "%s\n", start);
  fclose(fp);

  checkTwo(mass, allNodes, 0, lastNode);

  FILE *fp1;
  fp1 = fopen(file,"a");
  fprintf(fp1, "%s\n", end);
  fclose(fp1);

  return;
}

void checkTwo(int** mass, int *allNodes, int startNode, int lastNode)
{
  int linkedNode;
  
  FILE *fp;
  char file[] = "graph.txt";
  fp = fopen(file,"a");

  allNodes[startNode] = 1;

  for (linkedNode = 0; linkedNode < lastNode; linkedNode++)                  //подсчёт связанных вершин
    if ((mass[startNode][linkedNode] != 0) && (allNodes[linkedNode] == 0)) 
    {
      fprintf(fp,"%d -- %d\n", (startNode+1), (linkedNode+1));
      checkTwo(mass, allNodes, linkedNode, lastNode);
    }
  fclose(fp);
}

void menu_acts (void)
{
  printf("1: Show the adjacency matrix\n");
  printf("2: Check graph for connectivity\n");
  printf("3: Create file.txt to display our graph on the monitor\n");
  printf("4: Exit\n");
}