#include "monty.h"

vars var;

/**
 * main - Main LIFO, FILO program
 * @argc: The arguments
 * @argv: The pointer containing arguments
 * Return: (0 Success, 1 Failed)
 */
int main(int argc, char **argv)
{
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(argv[1], "r");
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		_free();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.temp, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
			if (_call(&var, opcode) == EXIT_FAILURE)
			{
				_free();
				return (EXIT_FAILURE);
			}
		var.line_number++;
	}

	_free();

	return (EXIT_SUCCESS);
}
