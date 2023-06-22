#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
*push - insert the element to the stack
*@stack: the pointer
*@line_number: number line of integers
*
*/
void push(stack_t** stack, unsigned int line_number)
{
	 int value = atoi(argument);
    char* argument = strtok(NULL, " \t\n");
     stack_t* new_node = malloc(sizeof(stack_t));

    if (argument == NULL || !isdigit(*argument))
    {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

   

   
    if (new_node == NULL)
    {
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}
/**
 *pall - print all elements on the stack
 *@stack: list of elements
 *@line_number: number of integer line to be printed 
 *
 */
void pall(stack_t** stack, unsigned int line_number)
{
	stack_t* current = *stack;
    (void)line_number; /* Unused parameter */
   

    
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

