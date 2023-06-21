#include "monty.h"


/**
 * _pchar - Main function that prints character
 * @stack: The double linked list
 * @line_number:  Execution file line
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	_free();
	exit(EXIT_FAILURE);
}

/**
 * print_str - Main function that prints string
 * @stack: The double linked list
 * @line_number:  execution File line
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (temp)
	{
		if (temp->n == 0)
			break;
		if (!isascii((temp)->n))
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
