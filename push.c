#include "monty.h"

/**
 * f_push - Adds a node to the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_push(stack_t **head, unsigned int counter)
{
	int num, index = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;
		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, num);
	else
		addqueue(head, num);
}
