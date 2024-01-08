#include "monty.h"

/**
 * push - adds a new element to the top of stack
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
 * pop - removes and returns element from the top of stack
 * @stack: pointer to top of stack
 * @line_number: line number of input file
*/
void pop(stack_t **stack, int line_number)
{
	if (*stack == NULL)
	{
		printf("L<line_number>: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	stack_t *i = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(i);
}

/**
 * pall- print all value at the top of stack
 * @stack: pointer to top of stack
*/
void pall(stack_t *stack)
{
	stack_t *s = stack;

	if (stack == NULL)
	{
		printf("L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}

	while (s != NULL)
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
	stack_t *stack = NULL;

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	pall(stack);
	pop(&stack, 1);
	pall(stack);
	pop(&stack, 1);
	pall(stack);

}
