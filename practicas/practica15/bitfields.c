#include <stdio.h>

// ^ - XOR
// | - OR
// & - AND
// << - Corrimiento a la izquierda
// >> - Corrimiento a la derecha 

typedef struct d {
	// ':' acota el tamanio del tipo de dato en bits
	unsigned char day:5;
	unsigned char month:4;
	unsigned char year;
} Date;

int main()
{
	Date today = {26, 4, 2018};
	printf("today is %d%d%d \n", today.day, today.month, today.year);
	//today.day += 10;

	if ((today.day ^ 26) == 0)
	{
		printf("Today is 26\n");
	}

	return 0;
}