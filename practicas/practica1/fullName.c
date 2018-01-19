#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int doFullName( char * firstName,
                char * lastName, 
                char ** fullNameValue ) // Apuntador que apunta al apuntador del arreglo de chars
{   
    // Init size of strings
    int sizeFirstName = strlen( firstName );
    int sizeLastName = strlen( lastName );
    int sizeFullName = sizeFirstName + sizeLastName + 1;

    // init new pointer for a new string
    char * fullName = (char *) malloc( sizeFullName * sizeof(char) );

    strcpy( fullName, firstName );
    strcpy( fullName + sizeFirstName, " "); // string of space(' ')
    strcpy( fullName + sizeFirstName + 1, lastName);
    *fullNameValue = fullName;

    return 0;
}

int main()
{
    char firstName[] = "Gera";
    char lastName[] = "Juarez";
    char * fullName;
    doFullName( firstName, lastName, &fullName );

    printf( "%s \n", fullName );
    free( fullName );       // Liberar espacio de memoria

    return 0;
}