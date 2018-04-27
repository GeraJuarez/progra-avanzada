#include <stdio.h>
#define MASK_FULL 0b010
#define MASK_DELETE 0b001

typedef struct s {
	char f:3;	
} Flags;

int main()
{
	Flags status;
	status.f = 0b110;

	if ((status.f & (MASK_FULL | MASK_DELETE) ) != 0)
	{
		printf("The data is full or deleted\n");
	}
	
	return 0;
}