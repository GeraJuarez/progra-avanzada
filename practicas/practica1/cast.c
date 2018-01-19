#include <stdio.h>

int main()
{
    int a = 250;
    long int d = a * (long)a;
    // Por default 'int' se le agrega al modificador.
    float f = 4.67;
    int e = 4;
    int c = (int)f + e;

    int j, k, l;
    int *p;

    p = &a;     // 'p' obtiene el valor de 'a'
    *p = 400;   // Modifica la variable 'a'
    p++;        // Cambia de rieccion
    *p = 5555;  // Modifica el valor de la direccion cambiada

    // Imprimir enteros: 'd' o 'i'
    // Imprimir modificador long: 'ld'
    // Imprimir float: 'f'
    // Imprimir hexadecimal: 'p' (usar '&' para la variable)
    //printf( "a = %p, d = %ld, f = %f, e = %d, c = %d \n", &a, d, f, e, c );
    printf( "a = %d, p = %p, j = %d, k = %d, l = %d \n", a, p, j, k, l );

    /*
        a = 2147483647, d = 1, f = 4.670000, e = 4, c = 8
        C empieza las operaciones de derecha a izquierda, primero hace
        una operacion y al final lo 'promueve' a long. Si se castea en
        la operacion, ya no se pierde informacion al hacer la operacion
        de enteros.

        Casteando segunda 'a' a long:
        a = 2147483647, d = 4611686014132420609, f = 4.670000, e = 4, c = 8

        Operaciones con floats y enteros es costoso si el resultado deseado
        es un entero. Tiene que convertir un valor a float y despues reconvertirlo.
    */

    return 0;
}