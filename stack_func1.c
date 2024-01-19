#include "monty.h"

void add_to_stack(stack_t **n_nd, __attribute__((unused))unsigned int ln)
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
	head = *n_nd;
	head->next = temper;
	temper->prev = head;
}

void print_top(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
		m_err(6, ln);
	printf("%d\n", (*stack)->n);
}


void pop_top(stack_t **stack, unsigned int ln)
{
	stack_t *temper;

	if (stack == NULL || *stack == NULL)
		m_err(7, ln);

	temper = *stack;
	*stack = temper->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temper);
}

void print_stack(stack_t **stack, unsigned int ln)
{
	stack_t *temper;

	(void) ln;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temper = *stack;
	while (temper!= NULL)
	{
		printf("%d\n", temper->n);
		temper = temper->next;
	}
}