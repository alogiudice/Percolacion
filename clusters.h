#include "head.h"

/* Esta función devuelve el tamaño de cada cluster del sistema en el array label.*/
/* Por ejemplo si resultados es = 20, quiere decir que hay clusters 1,2,3... con diferentes tamaños.  Lo que vamos a buscar es el tamaño de cada uno de estos clusters.
	En el array label, que es de tamaño resultado, vamos a obtener:

	Array "label":

    [0] [1] [2]  ...   [resultado - 1]
	| t_1 | t_2 | ... | t_último 
	-----------------------------------
	Tamaño de cada uno
	*/
int *clusters(int **red, int n, int m, int resultado)
	{
	int *label;
	int a = resultado;
	label = (int *)calloc(a, sizeof(int));
	int cont[a];
	
	/* Genero el vector labels usando la cantidad de clusters que devolvió el algoritmo. */
	
	/* Ahora, vamos a scanear la red buscando los diferentes clusters que hay en el sistema. */
	
	for(int f = 0; f < a; ++f)
		 {
			cont[f] = f + 1;
		 }
	for(int g = 0; g < a; ++g)
			{
			for(int i = 0; i < n; ++i)
				 {
	   			for(int j = 0; j < n; ++j)
	    			 {
	    				if(red[i][j] == cont[g] && red[i][j] != 0)
						   label[g]++;
	     			 }
	    	 	 }	
	   	}
	
	return label;	
	}
