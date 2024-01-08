#include "monty.h"

/**
 * push - pushed value in the stack
 * @stack: pointer to top of stack
 * @line_number: line number of input file
*/

void push(stack_t **stack, unsigned int line_number)
{
	struct stack_s *new;

	new = malloc(sizeof(struct stack_s));
	if (new == NULL)
	{
		printf("L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}

	*stack = new;
}

/**
 * pint - print value at the top of stack
 * @stack: - pointer to top of stack
*/
void pint(stack_t *stack)
{
	stack_t *s = stack;

	if (stack == NULL)
	{
		printf("L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}

	if (s != NULL)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}

/**
 * main - main function
 * Return: Nothing
*/
int main(void)
{
	struct stack_s *stack = NULL;

	push(&stack, 1);
	pint(stack);
	push(&stack, 2);
	pint(stack);
	push(&stack, 3);
	pint(stack);

}
