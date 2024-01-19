#include "monty.h"

void mod_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		m_err(8, ln, "mod");


	if ((*stack)->n == 0)
		m_err(9, ln);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

void mul_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, ln, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}