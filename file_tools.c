#include "monty.h"

void opener(char *fl_name)
{
	FILE *fd = fopen(fl_name, "r");

	if (fl_name == NULL || fd == NULL)
		my_er(2, fl_name);

	reader(fd);
	fclose(fd);
}


void finder(char *ocp, char *v, int ln, int f)
{
	int i;
	int ag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (ocp[0] == '#')
		return;

	for (ag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(ocp, func_list[i].opcode) == 0)
		{
			caller(func_list[i].f, ocp, v, ln, f);
			ag = 0;
		}
	}
	if (ag == 1)
		my_er(3, ln, ocp);
}

void reader(FILE *fd)
{
	int ln, f = 0;
	char *buff = NULL;
	size_t len = 0;

	for (ln = 1; getline(&buff, &len, fd) != -1; ln++)
	{
		f = parser(buff, ln, f);
	}
	free(buff);
}



void caller(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			my_er(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				my_er(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

int parser(char *buff, int ln, int f)
{
	char *ocp, *v;
	const char *delim = "\n ";

	if (buff == NULL)
		my_er(4);

	ocp = strtok(buff, delim);
	if (ocp == NULL)
		return (f);
	v = strtok(NULL, delim);

	if (strcmp(ocp, "queue") == 0)
		return (1);
	if (strcmp(ocp, "stack") == 0)
		return (0);

	finder(ocp, v, ln, f);
	return (f);
}
