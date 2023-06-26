#include "monty.h"

void push(stack* stack, int value, int line_number)
{
	if (stack->top == stack_size - 1)
	{
		printf("Error: L%d: stack overflow\n", line_number);
		exit (EXIT_FAILURE);
	}
	stack->data[++stack->top] = value;
}

void pall(stack* stack)
{
	int i;

	for (i = stack->top; i >= 0; i--
			)
