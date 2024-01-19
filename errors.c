#include "monty.h"

void Serr(int errCode, ...)
{
	va_list ag;
	int mo;

	va_start(ag, errCode);
	mo = va_arg(ag, int);
	switch (errCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", mo);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", mo);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void my_er(int errCode, ...)
{
	va_list ag;
	char *one_piece;
	int mo;

	va_start(ag, errCode);
	switch (errCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			mo = va_arg(ag, int);
			one_piece = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", mo, one_piece);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

void m_err(int errCode, ...)
{
	va_list ag;
	char *one_piece;
	int mo;

	va_start(ag, errCode);
	switch (errCode)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			mo = va_arg(ag, unsigned int);
			one_piece = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", mo, one_piece);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

