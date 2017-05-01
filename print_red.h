#include "head.h"
/*Esta función sòlo muestra los contenidos de la red en pantalla.
Està hecha para debuggear algunas cosas a mano o ver que todo anda bien. */

void print_red(int **red, int n)
	{
	for(int i = 0; i < n; ++i)
		{
		printf("\n");
		
	   for(int j = 0; j < n; ++j)
	    	{
	    	printf("%d ", red[i][j]);
	     	}
	   }	
		printf("\n");
	}
