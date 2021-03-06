#include "monty.h"
tool tools = {NULL, NULL, NULL, NULL};
/**
 * main - Program that interprets bytecode (.m) and execute opcode
 * @argn: number of arguments.
 * @argv: Arguments passed to the program.
 * Return: always 0 and on error EXIT_FAILURE
 **/
int main(int argn, char *argv[])
{
	int line_num = 1;
	int read = 0;
	size_t linea = 0;
	stack_t *head = NULL;

	if (argn != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	tools.archivoM = fopen(argv[1], "r");
		if (!tools.archivoM)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

	while ((read = getline(&tools.buffer, &linea, tools.archivoM)) != EOF)
	{
		toquenizar(tools.buffer);
		if (tools.comando != NULL && tools.comando[0] != '#')
			instruccion(line_num, tools.comando, &head);
		line_num++;
	}
	_free(head);
	return (0);
}
