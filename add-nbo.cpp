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
	
	uint64_t result = 0;
	
	printf("%s Data is : %u\n", argv[1], ntohl(input1));
	printf("%s Data is : %u\n", argv[2], ntohl(input2));

	result = (uint64_t)(ntohl(input1) + ntohl(input2));	

	printf("Result : %d\n", result);
	return 0;
}
