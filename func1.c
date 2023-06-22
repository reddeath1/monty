#include "monty.h"

/**
 * print_char - Main function that prints character
 * @stack: The double linked list
 * @line_number:  Execution file line
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
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
		if ((temp)->n < 127 || (temp)->n < 0)
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
