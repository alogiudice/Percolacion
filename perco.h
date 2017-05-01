#include "head.h"
/*Lo que hago con esta función es barrer toda la primera fila, e ir comparàndola con los valores para cada i,j de la ùltima. SIn hay coincidencia, el sistema percolò. */

int perco(int **red, int n, int m)
	{
	int i,j, nclu;
	nclu = 0;
	for(j = 0; j < n; ++j)
	   {
	   for(i = 0; i < m; ++i)
	      {
	      if(red[0][j] == red[n][i])
		{
		/*La red percoló */
		nclu++; 
		}
	      }
	   }
	return(nclu);	
	}
