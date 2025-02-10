/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:56:10 by bailey            #+#    #+#             */
/*   Updated: 2025/02/11 02:11:15 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates new node and returns the pointer of it
// Allocate memory for a new node.
// Set the node's value.
// Initialize the index to -1.
// set to NULL, meaning this node doesn’t yet point to another node.
t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

// Adds the specified node to a stack (list) making it the head
//Insert a new node at the beginning of the linked list.
// Set the new node's next pointer to the current head.
// Update the head of the list to be the new node
void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}

// Find and Returns the last node of a list 
//Start with the head of the list.
// Traverse the list until the next pointer is NULL.
//Move tmp to the next node.
// If the next pointer of the current node is NULL,
//then this node is the last node, so return it
// In case the list is empty or loop ends naturally
t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

// Adds the specified node to a stack (list) making it the last node
//Append a new node at the end of the linked list.
// If the list is not empty,
// Find the last node.
// Set the last node's next pointer to the new node.
// New node's next is NULL.
// The new node becomes the head.
void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*n;

	if (*stack)
	{
		n = ft_lstlast(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

// Returns the size of the Linked List
// Count and return the number of nodes in the linked list.
//starts at head uses a temporary pointer to traverse the list.
//while there is a node
//move to the next node
//increments count
int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// Prints the Linked List
//Display all the numbers in the linked list.
// Start at the head.
// Loop through the list until no nodes remain.
//Print the value of the current node to file descriptor 1 (standard output).
// Print a newline.
// move to he next node
/*void	printlist(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
*/