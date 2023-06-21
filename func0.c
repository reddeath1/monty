#include "monty.h"

/**
 * _add - Main function that adds the top two elements of the stack
 * @stack: Linked list
 * @line_number: File execution line
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _sub - Main function that substracts the top two elements of the stack
 * @stack: linked list
 * @line_number: line counter
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _div - Main function that divides the top two elements of the stack
 * @stack: Linked list
 * @line_number: line counter
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _mul - Main function that multiply two or more numbers together
 * @stack: The double linked list
 * @line_number: Execution file line
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	_pop(stack, line_number);
}

/**
 * mod - Main function that calculates the remeinder (modulus)
 * @stack: Double linked list
 * @line_number File line execution
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
}
