#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "lib1.h"
#include "lib_gr6.h"
#include <time.h>
int main (int argc, char* argv[])
{
if(argc>3)
{
double T1,T2,T3;
int N=10000;
clock_t tiempo_inicio,tiempo_fin;
double tiempo_usado=0;
unsigned char search='\n';
double vect_len;
char* buffer;
char* buffer_aux;
unsigned int ls_buff_len;
double vector[N];
buffer = read_file_to_buffer (argv[2], &ls_buff_len);
char *numero=buffer;
printf("%s",buffer);

if(buffer!=NULL)
{
tiempo_inicio=clock();
for (int cont =0; cont < N; cont++)
{
vector[cont]=atof(buffer);
buffer=strchr(buffer, search);
buffer+=1;
}
printf("...\n\n");
tiempo_fin=clock();
tiempo_usado=(double)(tiempo_fin - tiempo_inicio)/CLOCKS_PER_SEC;
T1=tiempo_usado;
}
else
{
printf("Error: Apuntador a buffer es nulo");
}

if(*argv[1]=='2')
{
int i, j,temp;
vect_len = sizeof(vector)/sizeof(vector[0]);
printf("Secuencia Original: \n");
print(vector, vect_len);

tiempo_inicio=clock();

bubble(vector, vect_len);
printf("\nSecuencia Ordenada: \n");

tiempo_fin=clock();
tiempo_usado=(double)(tiempo_fin - tiempo_inicio)/CLOCKS_PER_SEC;
T2=tiempo_usado;
printf("tiempo de ejecucuion bubble: \n%.10f\n\n",tiempo_usado);

print(vector, vect_len);

tiempo_inicio=clock();

write_dArray_to_file (vector, vect_len, argv[3]);

tiempo_fin=clock();
tiempo_usado=(double)(tiempo_fin - tiempo_inicio)/CLOCKS_PER_SEC;
printf("\n\ntiempo de ejecucuion guardado: \n%.10f\n\n",tiempo_usado);
printf("\n\ntiempo de ejecucuion: \n%.10f\n\n",T1);

printf("\n\ntiempo de ejecucuion bubble: \n%.10f\n\n",T2);

}
else if (*argv[1]=='1')
{

vect_len=sizeof(vector)/ sizeof(vector[0]);
printf("Secuencia original : \n");
printArr(vector,vect_len);

tiempo_inicio=clock();

insert(vector,vect_len);
printf("\nsecuencia ordenada: \n");

tiempo_fin=clock();
tiempo_usado=(double)(tiempo_fin - tiempo_inicio)/CLOCKS_PER_SEC;
T3=tiempo_usado;

printArr(vector,vect_len);

tiempo_inicio=clock();

write_dArray_to_file (vector, vect_len, argv[3]);

tiempo_fin=clock();
tiempo_usado=(double)(tiempo_fin - tiempo_inicio)/CLOCKS_PER_SEC;
printf("\n\ntiempo de guardado: \n%.10f\n\n",tiempo_usado);
printf("\n\ntiempo de ejecucuion insert: \n%.10f\n\n",T3);
printf("tiempo de ejecucuion: \n%.10f\n\n",T1);

}
else
{
printf("Error:Argumento para ordenamiento de numeros no valido");
}
free_buffer_mem(buffer);
}
else
{
printf("Error: Faltan argumentos de entrada");
}
return 0;
}
