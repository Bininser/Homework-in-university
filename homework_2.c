#include "stdio.h"

int grapf[7][7] = 
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
    if ((grapf[startNode][linkedNode] != 0) && (nodes[linkedNode] == 0)) 
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
  	printf("This is our grapf \n");
  	for (int i = 0; i < 7; i++)
  	{
  		for (int j = 0; j < 7; j++)
  		{
  			printf(" %d ", grapf[i][j]);
  		}
  		printf(" \n");
  	}
  	search(0,7,numLinkes);
  	if (numLinkes = 6)
  	{
  		printf("Grapf is linked\n");
  	}	
  	else
  	{
  		printf("Grapf not linked\n");
  	}
	return 0;
}