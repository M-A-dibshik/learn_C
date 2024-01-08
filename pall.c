#include "monty.h"
/**
  * pall -  prints all the values on the stack, starting from the top of the stack.
  * @stack: pointer to the top of the stack
  * @line_number: line number of the input file
  * 
  * Return: void
  *  */
 void pall(stack_t **stack, unsigned int line_number)
 {
    stack_t *tmp = *stack;
    int i = 0;

    if (*stack == NULL)
    return;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
        i++;
    }
}

/**
  * pint -  prints the value at the top of the stack, followed by a new line.
  * @stack: pointer to the top of the stack
  * @line_number: line number of the input file
  * 
  * Return: void
 */
 void pint(stack_t **stack, unsigned int line_number)
 {
    if (*stack == NULL)
    {
        fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *elem = *stack;
    while (elem != NULL)
    {
        printf("%d\n", elem->n);
        elem = elem->next;
    }
}
/**
 * push - pushes an elements to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the input file
 * @value: value to pushed
 * 
 * Return: address of the new element
*/
 void push(stack_t **stack, unsigned int line_number)
 {
    stack_t *new_node;
	new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    new_node->n = line_number;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack != NULL)
    (*stack)->prev = new_node;
    *stack = new_node;
    printf("%d\n",line_number);
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
   // pint(&stack, 1);
   // push(&stack, 3);
    pall(&stack, 1);
}
