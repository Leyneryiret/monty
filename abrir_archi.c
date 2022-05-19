#include "monty.h"

/**
 * open_file - Opens a file to interpret the commands within
 * @abrir_archi: The file to be opened
 *
 * Return: The file descriptor of the opened file
 */
void abrir_archi(int argumentos, char *archivo)
{
  if (argumentos != 2)
    {
      fprintf (stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }

  tools.archivoM = fopen(archivo, "r");

  if (!archivo)
    {
      fprintf(stderr, "Error: Can't open file %s\n", archivo);
      exit(EXIT_FAILURE);
    }

}