#include <stdio.h>
#include <stdlib.h>



void print_factors(long long int n)
{
	long long int i;
	if (n % 2 == 0)
	{
		printf("%lld=%lld*%d\n", n, n / 2, 2);
		return;
	}

	for (i = 3; i <= n / 2; i += 2)
	{
		if (n % i == 0)
		{
			printf("%lld=%lld*%lld\n", n, n / i, i);
			break;
		}
	}
}

int main(int argc, char **argv)
{
	char *buffer = NULL;
	FILE *fd;
	size_t l= 0;
	ssize_t stat;
	long long int number;
	if (argc != 2)
		return (EXIT_FAILURE);

	fd = fopen(argv[1], "r");
	if (fd == NULL)
		return (EXIT_FAILURE);
	stat = getline(&buffer, &l, fd);

	while (stat != -1)
	{
		number = atoll(buffer);
		free(buffer);
		buffer = NULL;
		l = 0;
		print_factors(number);
		stat = getline(&buffer, &l, fd);
	}
	fclose(fd);
	return (EXIT_SUCCESS);

}

