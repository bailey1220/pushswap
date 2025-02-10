/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:55:51 by bailey            #+#    #+#             */
/*   Updated: 2025/02/11 02:08:44 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// set to Null if havent found any candidate node yet.
// Boolean flag: 0 means false (no minimum candidate yet
// Start at the head of the list.
//head->index == -1 only considers nodes thats not assign index yet.
//no candidtes selected, set current node become candidate
//else if the current node’s value is less than the candidate’s value, 
//update the candidate.
// Update min to point to this node.
//flag 1 means TRUE :We now have a candidate.
// Move to the next node in the list.
// Return the node with the smallest unindexed value.
#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

// Return the node with the smallest unindexed value.
// Continue while there is an unindexed node.
// Set the node's index, then increment index.
// find the next smallest unindexed node.
//scans the list again but skips nodes whose index is not -1.
void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
