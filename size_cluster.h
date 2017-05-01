#include "head.h"
/*Lo que hago con esta función es barrer toda la primera fila, e ir comparàndola con los valores para cada i,j de la ùltima. SIn hay coincidencia, el sistema percolò. */

int size_cluster(int **red, int n, int m, int etiqueta)
	{
	int i,j, nclu;
	nclu = 0;
	for(j = 0; j < n; ++j)
	   {
	   for(i = 0; i < m; ++i)
	      {
	      if(red[i][j] == etiqueta)
	      	{
	      	nclu++;
	      	}
	      }
	   }
	return(nclu);	
	}
