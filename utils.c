#include "monty.h"

/**
 * _vars - Main function that fakes rand to jackpoint Giga Millions
 * @var: The global variables to initialize
 * Return: (0 Success, 1 Failed)
 */
int _vars(vars *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->temp = 0;
	var->dict = instructions();
	if (var->dict == NULL)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * instructions - Main function that creates new function dictionary
 * Return: (A dictionary pointer)
 */
instruction_t *instructions()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = _pall;
	ptr[1].opcode = "push", ptr[1].f = _push;
	ptr[2].opcode = "pint", ptr[2].f = _pint;
	ptr[3].opcode = "pop", ptr[3].f = _pop;
	ptr[4].opcode = "swap", ptr[4].f = _swap;
	ptr[5].opcode = "add", ptr[5].f = _add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = _sub;
	ptr[8].opcode = "div", ptr[8].f = _div;
	ptr[9].opcode = "mul", ptr[9].f = _mul;
	ptr[10].opcode = "mod", ptr[10].f = _mod;
	ptr[11].opcode = "pchar", ptr[11].f = print_char;
	ptr[12].opcode = "pstr", ptr[12].f = print_str;
	ptr[13].opcode = "rotl", ptr[13].f = _rotl;
	ptr[14].opcode = "rotr", ptr[14].f = _rotr;
	ptr[15].opcode = "stack", ptr[15].f = stack;
	ptr[16].opcode = "queue", ptr[16].f = queue;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * _call - Main function that calls a Function
 * @var: The global variables
 * @opcode: The Command to execute
 * Return: (Always)
 */
int _call(vars *var, char *opcode)
{
	int i;

	for (i = 0; var->dict[i].opcode; i++)
		if (strcmp(opcode, var->dict[i].opcode) == 0)
		{
			if (!var->dict[i].f)
				return (EXIT_SUCCESS);
			var->dict[i].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * _free - Clean all program mallocs
 * Return:  (Always)
 */
void _free(void)
{
	if (var.buff != NULL)
		free(var.buff);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * _isdigit - Main function that checks if character is digit or not
 * @str: Num to validate
 * Return: (0 Success, 1 Failed)
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
	}
	return (0);
}
