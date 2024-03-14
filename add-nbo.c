#include "add-nbo.h"

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("syntax : add-nbo <file1> <file2>\n");
		return (0);
	}

	uint32_t	num1 = 0;
	uint32_t	num2 = 0;

	FILE		*file1 = fopen(argv[1], "r");
	FILE		*file2 = fopen(argv[2], "r");

	fread(&num1, sizeof(uint32_t), 1, file1);
	fread(&num2, sizeof(uint32_t), 1 ,file2);

	num1 = _my_ntohl(num1);
	num2 = _my_ntohl(num2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);

	fclose(file1);
	fclose(file2);

	return (0);
}

uint32_t	_my_ntohl(uint32_t num)
{
	uint32_t	result;

	result = ((num & 0x000000FF) << 24 | (num & 0x0000FF00) << 8 |
			(num & 0x00FF0000) >> 8 | (num & 0xFF000000) >> 24);

	return (result);
}
