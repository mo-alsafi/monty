#include "monty.h"

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *temper;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temper = *stack;
	while (temper != NULL)
	{
		ascii = temper->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		temper = temper->next;
	}
	printf("\n");
}

void print_char(stack_t **stack, unsigned int ln)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		Serr(11, ln);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		Serr(10, ln);
	printf("%c\n", ascii);
}

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temper;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temper = *stack;

	while (temper->next != NULL)
		temper = temper->next;

	temper->next = *stack;
	temper->prev->next = NULL;
	temper->prev = NULL;
	(*stack)->prev = temper;
	(*stack) = temper;
}

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temper;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temper = *stack;
	while (temper->next != NULL)
		temper = temper->next;

	temper->next = *stack;
	(*stack)->prev = temper;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
