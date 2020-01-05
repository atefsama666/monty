#include "monty.h"

/**
* push - pushes into the stack at the top
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/
void push(stack_t **top, unsigned int line_number)
{
stack_t *newStack;
int number;
(void) line_number;
newStack = malloc(sizeof(stack_t));
if (!newStack)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
if (globaldata->number[0] == '0')
number = 0;
else if (atoi(globaldata->number) == 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
else
number = atoi(globaldata->number);
newStack->n = number;
if (*top == NULL)
{
newStack->prev = NULL;
newStack->next = NULL;
*top = newStack;
}
else
{
(*top)->next = newStack;
newStack->prev = (*top);
newStack->next = NULL;
*top = newStack;
}
}

/**
* pall - prints all stack
* @top: the top of the stack
* @line_number: value of arguments
* Return: exit status.
*/
void pall(stack_t **top, unsigned int line_number)
{
stack_t *newStack;
(void) line_number;
if (*top == NULL)
return;
newStack = (*top);
while (newStack)
{
printf("%d\n", newStack->n);
newStack = newStack->prev;
}
}