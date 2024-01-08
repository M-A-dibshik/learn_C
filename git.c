#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, unsigned int line_number) {
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    new_node->n = line_number;
    new_node->next = *stack;
    new_node->prev = NULL;
    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }
    *stack = new_node;
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *tmp = *stack;

    if (*stack == NULL)
        return;

    while (tmp != NULL) {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}

int main(void) {
    stack_t *stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    pall(&stack, 1);

    return 0;
}
