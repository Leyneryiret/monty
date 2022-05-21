#include "monty.h"
/**
 * _div - divides the second top element of the stack by the top element of the stack.
 * @h: pointer to the head of the stack
 * @line_num: Number of the current line.
 * Return: Nothing it is a void function.
 */
void _div(stack_t **h, unsigned int line_num)
{
	stack_t *aux = *h;
	int new = 0;

	if ((*h) == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*h)->n == 0)
{
			    
		fprintf(stderr, "L%u: division by zero", line_num);
	}


	new = aux->next->n / aux->n;
	(*h) = aux->next;		aux->next->n = new;
	if (aux->next)
		aux->next->prev = NULL;
	free(aux);
}