#include <stdio.h>

typedef union i{
	unsigned char parts[4];
	unsigned dir;
} IpAddress;

int main()
{
	IpAddress myAddress;
	myAddress.parts[0] = 127;
	myAddress.parts[1] = 0;
	myAddress.parts[2] = 0;
	myAddress.parts[3] = 1;

	printf("The number is %d\n", myAddress.dir);
	myAddress.dir += 1;
	printf("The %d %d\n", myAddress.parts[0], myAddress.parts[3]);

	return 0;
}