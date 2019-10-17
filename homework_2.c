#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

int graf[7][7] = 
 {{ 0, 1, 1, 0, 0, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0 } };

int nodes[7]; 	// вершины графа
int numLinkes; 	//количество связей

void search(int startNode, int lastNode,int n)
{
  int linkedNode;
  nodes[startNode] = 1;
  for (linkedNode = 0; linkedNode < lastNode; linkedNode++)
    if ((graf[startNode][linkedNode] != 0) && (nodes[linkedNode] == 0)) 
    {
    	printf("%d -> %d. Nodes are linked\n", startNode+1,linkedNode+1);
    	n++;
     	search(linkedNode, lastNode, n);
    }
}

int main ( void )
{
	numLinkes = 0;
  	for (int i = 0; i < 7; i++)
  	{
  		nodes[i] = 0;
  	}
  	printf("This is our graf \n");
  	for (int i = 0; i < 7; i++)
  	{
  		for (int j = 0; j < 7; j++)
  		{
  			printf(" %d ", graf[i][j]);
  		}
  		printf(" \n");
  	}
  	search(0,7,numLinkes);
  	if (numLinkes = 6)
  	{
  		printf("Graf is linked\n");
  	}	
	return 0;
}