#include "monty.h"

void swap_nodes(stack_t **stack, unsigned int ln)
{
	stack_t *temper;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, ln, "swap");
	temper = (*stack)->next;
	(*stack)->next = temper->next;
	if (temper->next != NULL)
		temper->next->prev = *stack;
	temper->next = *stack;
	(*stack)->prev = temper;
	temper->prev = NULL;
	*stack = temper;
}

void nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}

void div_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, ln, "div");

	if ((*stack)->n == 0)
		m_err(9, ln);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

void add_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, ln, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


void sub_nodes(stack_t **stack, unsigned int ln)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		m_err(8, ln, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


