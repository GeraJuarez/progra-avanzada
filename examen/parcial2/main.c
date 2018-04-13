// Gerardo Cesar Juarez Lopez
// A00226860
/* Solucion: 
  * Tomar el tamanio de 'p' y 'v' como P y V.
  * Iterar por cada caracter de 'p'
  * Por cada caracter, tomar los V caracters siguientes y comararlo con 'v'
  * Si el contador de matches en cada indice es igual al tamanio de V o V - 1, entonces imprimir el indice donde se tomo el substring

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100000
#define NEGATIVE "No Match!"

void analyzeDNA(char* patient, char* virus)
{
	int pSize = strlen(patient);
	int vSize = strlen(virus);
	int hasMatch = 0;
	int matches = 0;

	if (vSize > pSize)
    // Check when virus DNA is greater than patient DNA
	{
		printf("%s\n", NEGATIVE);
		return;
	}
	
    // Init temporat substring
	char* tempSubstring = (char*) malloc( vSize * sizeof(char) );

	for (int i = 0; i < pSize; i++)
	{
        // Copy a string with a lenght of vSize on each position
		strncpy(tempSubstring, &patient[i], vSize);
		//printf("%s\n", tempSubstring);

		if (strlen(tempSubstring) < vSize)
        // Almost end of the patient DNA, which means that what is left is smaller that virtus DNA
		{
			break;
		}

		for (int j = 0; j < vSize; j++)
        // Count mathes
		{
			if (tempSubstring[j] == virus[j])
			{
				matches++;
			}
		}

		if (matches == vSize || matches == vSize - 1)
		{
			hasMatch = 1;
			printf("%d ", i);
		}

		matches = 0;
	}

	if (!hasMatch) 
	{
		printf("%s\n", NEGATIVE);
		return;
	}
	else
	{
		printf("\n");
	}
}

int main() {
	//FILE* inFile = freopen("data/sample-Save.1.in", "r", stdin);
	int test;
	char p[MAX_INPUT_SIZE];	// patient
	char v[MAX_INPUT_SIZE];	// virus
	scanf("%d", &test);	

	for (int i = 0; i < test; i++)
	{
		scanf("%s %s", p, v);
		analyzeDNA(p, v);
	}

	//fclose(inFile);
	return 0;
}
