#include "monty.h"
#include <string.h>

bus_t bus;

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	char buffer[1024];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		if (buffer[0] != '\0' && buffer[0] != '\n')
		{
			content = (char *)malloc(strlen(buffer) + 1);
			if (!content)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			strcpy(content, buffer);
			bus.content = content;
			counter++;
			execute(content, &stack, counter, file);

			free(content);
		}
	}
	fclose(file);
return (0);
}
