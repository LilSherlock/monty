#include "monty.h"

/**
 * deleteNode - remove the head at the end linked list
 *
 * @head: Header
 * @vector: index
 *
 * Return: 1 if succed or -1 if its wrong
 */

int deleteNode(stack_t **head, stack_t *vector)
{
	if (*head == NULL || vector == NULL)
		return (-1);
	if (*head == vector)
		*head = vector->next;
	if (vector->next != NULL)
		(vector->next)->prev = vector->prev;
	if (vector->prev != NULL)
		(vector->prev)->next = vector->next;
	free(vector);
	return (1);
}
/**
 * delete_dnodeint_at_index - remove the head at the end linked list
 *
 * @head: Header
 * @index: index
 *
 * Return: The position of the last add node, or null if fails
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i;
	stack_t *vector;
	int value = 0;

	if (head == NULL)
		return (-1);
	vector = *head;
	/*go to the pos*/
	for (i = 0; vector != NULL && i < index; i++)
	{
		vector = vector->next;
	}
	if (vector == NULL)
		return (-1);
	value = deleteNode(head, vector);
	if (value == 1)
		return (1);
	return (-1);
}
/**
 * add_dnodeint_end - print list
 *
 * @head: head
 * @n: n to add
 *
 * Return: double list
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *vector, *reference;

	vector = malloc(sizeof(stack_t));
	if (vector == NULL)
	{
		return (NULL);
	}
	vector->n = n;
	vector->next = 0;
	if (*head == NULL)
	{
		*head = vector;
	}
	else
	{
		reference = *head;
		while (reference->next != NULL)
		{
			reference = reference->next;
		}
		reference->next = vector;
		vector->prev = reference;
		vector->next = NULL;
	}
	return (vector);
}

/**
 * rotl - change first and last
 *
 * @stack: pointer to head of stack
 * @line_number: Number of line
 *
 * Return: length of stack
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *vector;
	int n;

	(void)line_number;
	if ((*stack) != NULL)
	{
		vector = (*stack)->next;
		if (vector != NULL)
		{
			n = (*stack)->n;
			delete_dnodeint_at_index(stack, 0);
			add_dnodeint_end(stack, n);
		}
	}

}
