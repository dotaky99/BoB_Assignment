#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("adsada");
	FILE *fd;
	uint32_t num;
	int i=0;
	uint32_t result = 0;
	for(i=1; i<argc; i++)
	{
		fd = fopen(argv[i], "rb");
		fread(&num, sizeof(uint32_t), 1, fd);
		num = ntohl(num);
		result += num;
		if(i==1)
			printf("%d(0x%x) + ", num, num);
		else
			printf("%d(0x%x) = " ,num, num);
	}
	printf("%d(%x)\n", result, result);
	fclose(fd);
	return 0;
}
