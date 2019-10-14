#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXDATA 100  //максимальное количество элементов множества

void start_menu();
void next_steb (char *mass[]);

int main ( int argc, char *argv[] ) {			//выбор одного из двух множеств
	int num;
	char *mass_1[MAXDATA];
	char *mass_2[MAXDATA];
	start_menu();
	scanf ("%d", &num);
	if (num <= 2 && num !=0)
	{
		switch(num) {
			case 1:
				next_steb(mass_1);
				break;
			case 2:
				next_steb(mass_2);
				break;
			default:
				printf("You did not select an array. Enter 1 or 2.\n");
				start_menu();
				break;
		}
	}
	else
	{
		printf("You did not select an array. Enter 1 or 2.\n");
		start_menu();
	}
	system ("pause");
	return 0;
}

void create_mass( char *m_e[], int *lenght);
void show_mass( char *m_e[], int *lenght);
void add_element( char *m_e[], int *lenght);
void del_element( char *m_e[], int *lenght);
void second_menu();

void next_steb (char *mass[]) {		//выбор действия с множеством
	int act = 0,
		size_0 = 0;
	int *size = &size_0;
	second_menu();
	while (act <= 5)
	{
		scanf (" %d",&act);
		getchar();
		switch(act) 
		{
			case 1:
				create_mass(mass, size);
				second_menu ();
				break;
			case 2:
				show_mass(mass, size);
				second_menu ();
				break;
			case 3:
				add_element(mass, size);
				second_menu ();
				break;
			case 4:
				del_element(mass, size);
				second_menu () ;
				break;
			case 5:
				return;
				break;
			default:
				printf("You have not selected an action. Enter what is suggested.\n");
				second_menu ();
				break;
		}
	}
	return;
}

void create_mass( char *m_e[], int *lenght) {												//создание множества
	int size_m,
		c,
		len = 0;
	printf("Enter the required number of elements (not more than 100)\n");
	scanf("%d", &size_m);
	getchar();
	while ( size_m > MAXDATA )
	{
		printf ("Can't you read ? Try again.\n");
		scanf(" %d", &size_m);
	}
	char *copy_set = (char*) malloc((size_m+1) * sizeof(int));
	printf("Enter items.\n");
	for (int i = 0; i < size_m; ++i)
	{
		while ( (c=getchar()) != EOF && c != ' ' && c != '\n') {
			copy_set[len++] = c;
		}
		copy_set[len] = '\0';
		m_e[(*lenght)++] = strdup(copy_set);
		len = 0;
	}
	free(copy_set);
	return;
}

void show_mass( char *m_e[], int *lenght) {										//вывод множества на экран
	printf("Elements of the set:\n");
	for (int i = 0; i < *lenght; i++)
	{
		printf("%d - %s; ", i+1, m_e[i]);
	}
	printf("\n");
	return;
}

void add_element( char *m_e[], int *lenght) {										//добавление элемента
	int c,
		len = 0;
	printf("Which element do you want to add.\n");
	char *copy_set = (char*) malloc((*lenght+1) * sizeof(int));
	while ( (c=getchar()) != EOF && c != ' ' && c != '\n') {
			copy_set[len++] = c;
	}
	copy_set[len] = '\0';
	m_e[(*lenght)++] = strdup(copy_set);
	free(copy_set);
	return;
}

void del_element( char *m_e[], int *lenght) {										//удаление элемента
	int num;
	printf("Enter the number of the item you want to delete:\n");
	scanf( "%d" , &num );
	if ( num == *lenght )
	{
		m_e [num-1] = m_e [*lenght+1];
	}
	else
	{
		for (int j = num-1; j < *lenght-1; j++)
		{
			m_e[j] = m_e [j+1];
			m_e[j+1] = 0 ;
		}
	}
	(*lenght)--;
	return;
}

void start_menu ( void ) {
	printf("Choose the set you want to work with.\n");
	printf("1 - With the first\n");
	printf("2 - With the second\n");
}

void second_menu ( void ) {
	printf("You can do the following:\n");
	printf("1 - Enter the set itself (if you have not set it yet)\n");
	printf("2 - Display set on screen\n");
	printf("3 - Add element\n");
	printf("4 - Delete element\n");
	printf("5 - End work\n");
}