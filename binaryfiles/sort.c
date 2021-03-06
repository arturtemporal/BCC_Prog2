#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000000

int cmpfunc (const void * a, const void * b) {
   return ( *(long int*)a > *(long int*)b );
}

// 
int main()
{

// inicializa ponteiros
    FILE* long_int_f;
    long int *long_int_a = (long int*)malloc(SIZE * sizeof(long int));

// abre e le o arquivo em long_int_a
    long_int_f = fopen("./long_integers", "r");
    fread(long_int_a, sizeof(long int), SIZE, long_int_f);
    
// organiza o arquivo
    qsort(long_int_a, SIZE, sizeof(long int), cmpfunc);

// escreve no arquivo em disco
    freopen("./long_integers", "w", long_int_f);
    fwrite(long_int_a, sizeof(long int), SIZE, long_int_f);

// libera a memoria
    free(long_int_a);
    fclose(long_int_f);
    return 0;
}
