#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <string.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	
	FILE *fp1 = fopen(argv[1], "rb");
	FILE *fp2 = fopen(argv[2], "rb");

	char buf1[4] = {'\0', };
	char buf2[4] = {'\0', };


	uint32_t input1 = 0x0;
	uint32_t input2 = 0x0;

	fread(&input1, sizeof(uint32_t), 1, fp1);
	fread(&input2, sizeof(uint32_t), 1, fp2);
	
	//input1 = (uint32_t)buf1
	uint64_t result = 0;
	
	//printf("0x%X\n", buf1);
	
	printf("input1 is : %u\n", ntohl(input1));
	printf("input2 is : %u\n", ntohl(input2));

	

	return 0;
}
