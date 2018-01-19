#include <stdio.h>

int main() 
{   
    // Init arreglo: la cantidad puede ser omitida
    // int a[5] = {0}  (inicializa todos a 0)
    // int a[5] = {1, 2}  (el primee valor es 1, el segundo 2, y el resto 0)
    int a[] = {1, 2, 3, 4, 5};
    int *pa;
    pa = a;     // apuntador al arreglo
    *pa = 27;   // modificar la casilla 0
    // pa = 27;  modifica el apuntador
    pa[2] = 45; // modifica casilla 2 de 'a'
    *(pa + 3) = 200; // mpdifica casilla 3 de 'a'

    for ( int i = 0; i < sizeof(a) / sizeof(int); i++ )
    {
        printf( "a[%d] = %d ", i, a[i]);
    }
    printf("\n");

    return 0;
}