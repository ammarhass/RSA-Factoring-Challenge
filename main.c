#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * fun - function that chooses the opcode
 *
 * @line: string contain the line
 * Return: 0 or 1
 */

int fun(char *line)
{
	int n;
	char *delimiter = " \t\n\r";
	char *tok = strtok(line, delimiter);

	n = atoi(tok);
	int i, q;

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			q = n / i;
			printf("%d=%d*%d\n", n, q, i);
			return (0);
		}
	}
	return (0);
}

/**
 * main - main fucntion
 *
 * @argc: number of arguments to function main
 * @argv: array of pointer to char
 * Return: int
 */

int main(int argc, char **argv)
{
	char *line;
	size_t  n = 0;
	int i = 1;
	FILE *textfile;

	if (argc != 2)
	{
		exit(EXIT_FAILURE);
	}
	textfile = fopen(argv[1], "r");
	if (textfile == NULL)
	{
		exit(0);
	}
	while (i > 0)
	{
		line = NULL;
		i = getline(&line, &n, textfile);
		if (i > 0)
		{
			fun(line);
		}
		i++;
		free(line);
	}
	fclose(textfile);
	return (0);
}
