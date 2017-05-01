#include "hk2.h"
#include "head.h"
#include "clusters.h"
#include "print_red.h"

int hoshen_kopelman(int **matrix, int m, int n);
int *clusters(int **red, int n, int m, int resultado);

int main(int argc, char **argv)
	{
	int i,j,n, **red, *label;
	int resultado;
	
	float p, *clusters_tot, paso_p;
	
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
	
	/* Inicializo el array clusters_tot, que va a alojar la cantidad
	de clusters de tamaño s de todas las redes. 
	No sé cuánto tamano temdrá de antemano, así que uso el tam máx
	que puede llegar a tener. */
	
	for(i = 0; i < n*n; ++i)
		 {
		 fprintf(F, "s%d ", i);
		 }
		 
	fprintf(F, "\n");
	paso_p = PASO_P;
	clusters_tot = (float *)calloc(n*n, sizeof(float));
	red = (int **)calloc(n, sizeof(int*)); 
	
  	for(int i = 0; i < n; i++) 
   		red[i] = (int *)calloc(n, sizeof(int));
	
	for(int prob = 0; prob < PASO_P; ++prob)
		{
   		
		float prob_f = prob;
		p = (prob_f) / paso_p;
		fprintf(F, "%f ", p);
		for(int t = 1; t < NUM_PASADAS; ++t)
			{	 
			for(i = 0; i < n; ++i)
				{
	   		for(j = 0; j < n; ++j)
	   	   	{
					red[i][j] = (rand() < p*RAND_MAX);
	   	  	}
				}
	/* Ahora, quiero encontrar los clusters de la red. Uso el algoritmo
	de Hoshel-Kopelman. Esto me da la cantidad de clusters.*/
	
			resultado = hoshen_kopelman(red, n, n);
			
			label = clusters(red, n, n, resultado);
			
			/* Ahora, voy contando cuántos clusters de tamaño i hay. Barro todo 
			el array label, y chequeo si hay distintos clusters de igual tamaño.
			i es el tamaño en sí. */
			
			for(i = 0; i < resultado; ++i)
				{
				if(label[i] == i)
					++clusters_tot[i];	
				}	

					
			}
		/* Ahora que terminó la pasada, normalizo la cantidad de clusters que obtuve 
		por el área de la red y la cantidad de pasadas. */
		for(i = 0; i < resultado; ++i)
			{
			clusters_tot[i] /= (n*n * NUM_PASADAS);
			}	
		/* Y guardo los resultados en un archivo. */
		for(i = 0; i < resultado; ++i)
			{
			fprintf(F, "%f ", clusters_tot[i]);
			}
			
		fprintf(F, "\n");
		printf("Voy por el p = %f\n", p);
		
		}
free (label);
free(red);		
free(clusters_tot);
fclose(F);
return 0;
}
