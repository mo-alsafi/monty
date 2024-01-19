#include "monty.h"
stack_t *head = NULL;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opener(argv[1]);
	free_nodes();
	return (0);
}


/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *temper;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temper = head;
		head = head->next;
		free(temper);
	}
}

stack_t *create_node(int num)
{
	stack_t *nd;

	nd = malloc(sizeof(stack_t));
	if (nd == NULL)
		my_er(4);
	nd->next = NULL;
	nd->prev = NULL;
	nd->n = num;
	return (nd);
}

void add_to_queue(stack_t **n_nd, __attribute__((unused))unsigned int ln)
{
	stack_t *temper;

	if (n_nd == NULL || *n_nd == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_nd;
		return;
	}
	temper = head;
	while (temper->next != NULL)
		temper = temper->next;

	temper->next = *n_nd;
	(*n_nd)->prev = temper;

}

