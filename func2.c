#include "monty.h"

/**
 * _rotl - Main function that rotates the bits of a binary value to the left
 * @stack: The linked list
 * @line_number: Execution file line
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *st = *stack;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (st->next)
		st = st->next;
	st->next = *stack;
	(*stack) = (*stack)->next;
	st->next->next = NULL;
	st->next->prev = st;
}

/**
 * _rotr - Main function that rotates the bits of a binary value to the right
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*stack)->prev = temp;
	*stack = temp;

}

/**
 * stack - Data type for LIFO, FIFO
 * @stack: The linked list
 * @line_number:  execution file line
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 0;
}

/**
 * queue - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	var.MODE = 1;
}
