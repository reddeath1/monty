#include "monty.h"
/**
 * _pall - Main function to print list
 * @stack: The double linked list
 * @line_number: The execution file line
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _push - Main function to insert a new value in list
 * @stack: The double linked list
 * @line_number:The execution  file line
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *st = *stack;
	char *cha;

	cha = strtok(NULL, " \r\t\n");
	if (cha == NULL || (_isdigit(cha) != 0 && cha[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free();
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(cha);
	if (var.MODE == 0 || !*stack)
	{
		temp->next = *stack;
		temp->prev = NULL;
		if (*stack)
			(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		while (st->next)
			st = st->next;
		st->next = temp;
		temp->prev = st;
		temp->next = NULL;
	}
}

/**
 * print_last - Main function that prints last node
 * @stack: Linked list
 * @line_number: File line execution
 */
void print_last(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* _pop - Main function that  deletes top of list
* @stack: Linked list
* @line_number: File line execution
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		_free();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}

/**
 * _swap - Main function that deletes top of list
 * @stack: linked list
 * @line_number: File execution  line
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack is too short\n",
			line_number);
		_free();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
