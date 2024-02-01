#define _GNU_SOURCE
#include "monty.h"
<<<<<<< HEAD

bus_t bus = {NULL, NULL, NULL, 0};
=======
#include <string.h>

bus_t bus;
>>>>>>> 19b743c82ddb60ed7d29e1964efb929383efb4ca

/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
<<<<<<< HEAD
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

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

    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        bus.content = content;
        counter++;

        if (read_line > 0)
        {
            execute(content, &stack, counter, file);
        }

        free(content);
    }

    free_stack(stack);
    fclose(file);

    return (0);
=======
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
>>>>>>> 19b743c82ddb60ed7d29e1964efb929383efb4ca
}
