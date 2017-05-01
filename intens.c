#include "hk2.h"
#include "head.h"
#include "clusters.h"
#include "print_red.h"
#include "size_cluster.h"

int size_cluster(int **red, int n, int m, int etiqueta);
int hoshen_kopelman(int **matrix, int m, int n);
int *clusters(int **red, int n, int m, int resultado);

int main(int argc, char **argv)
	{
	int i,j,n, **red;
	int resultado, tama_cluster;
	
	float p, paso_p;
	
	FILE *F = fopen("resulta", "w"); /* El archivo 'resulta' va a ser en donde voy a alojar p vs núm de clusters. */
	
	n = M;
	
	srand( time(NULL) );
	
	if(F == NULL)
     {
      printf("No se pudo abrir el archivo!!");
      return (1);
     }

	
	/* Creamos una matriz aleatoria con probabilidad p de ocupación */
	/* Me defino la proba p como un número entre 0 y 1. p = rand() / (float)RAND_MAX*/
	paso_p = PASO_P;
	
	red = (int **)calloc(n, sizeof(int*)); 
  for(int i = 0; i < n; i++) 
   	 red[i] = (int *)calloc(n, sizeof(int));
	
	for(int prob = 0; prob < PASO_P; ++prob)
		{
		float prob_f = prob;
		p = (prob_f) / paso_p;
		
		for(int t = 1; t < NUM_PASADAS; ++t)
			{	 
			for(i = 0; i < n; ++i)
				{
	   		for(j = 0; j < n; ++j)
	   	   	{
					red[i][j] = (rand() < p*RAND_MAX);
	   	  	}
				}
	
		resultado = hoshen_kopelman(red, n, n);
		int cluster[resultado];
		for(i = 0; i < resultado; ++i)
			 {
			 cluster[i] = i+1;
			 }
				 
			/* Scaneo la red para ver si percoló. */
		tama_cluster = 0;
			
		for(int k = 0; k < resultado; ++k)
				{
				for(i = 0; i < n; ++i)
					 {
	   			 for(j = 0; j < n; ++j)
	   	   			{	
							if(red[0][i] == cluster[k] && red[n-1][j] == cluster[k])
							 	{
							  tama_cluster += size_cluster(red, n, n, cluster[k]);	
							  }
	   	  			}
					 }
				}
				
			}

		/* Y guardo los resultados en un archivo. */
		
		fprintf(F, "%f %d\n",p, tama_cluster);

		printf("Voy por el p = %f\n", p);
		}
		
free(red);		
fclose(F);
	
return 0;
	}
