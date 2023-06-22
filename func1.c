#include "monty.h"

/**
 * print_char - Main function that prints character
 * @stack: The double linked list
 * @line_number:  Execution file line
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if (!isASCII((*stack)->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
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
		if (!isASCII((*stack)->n))
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * isASCII - Main function that check if the string or int is int isacii
 * @value: argument
 * Return: always
 */

int isASCII(int value)
{
	return (value >= 0 && value <= 127);
}
