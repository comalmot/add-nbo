#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <string.h>
#include <netinet/in.h>

uint32_t ReadFromFile(char* filename) {
	uint32_t input = 0x0;

	FILE* fp = fopen(filename, "rb");
	if(fp = NULL)
		printf("fopen() Error!");
	int check = fread(&input, sizeof(uint32_t), 1, fp);
	
	fclose(fp);

	return ntohl(input);
}

int main(int argc, char *argv[]) {

	if(argc != 3) {
		printf("Usage : %s <filename1> <filename2>", argv[0]);
	}

	uint32_t input1 = ReadFromFile(argv[1]);
	uint32_t input2 = ReadFromFile(argv[2]);
	
	uint64_t result = 0x0;
	
	printf("%s Data is : %u\n", argv[1], input1);
	printf("%s Data is : %u\n", argv[2], input2);

	result = (uint64_t)input1 + input2;	

	printf("Result : %lu\n", result);

	return 0;
}
