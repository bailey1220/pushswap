/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bailey <bailey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 00:29:07 by bailey            #+#    #+#             */
/*   Updated: 2025/02/10 22:56:07 by bailey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//determines how many bits are required for the largest number in stack_a.
// points to 1st node
//stores first node in max
//check if current node is greater than max
// if yes updates node to the new larger value
//if not move to the next nodes
//count number of bits to represent our max
//increments i 
static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
// maxbits -tell how many sorting passes are needed
//assigns the first element of the linked list (stack_a) to head_a
//stores the number of elemeents in size
//find number of bits needed for largest number
//find number of bits needed for largest number
//runs each bit position (from 0th bit to max_bit)
//go through all number in stack a
//get first element in stack a
// shifts the binary representation of index to the right by i places.
// The & 1 isolates the rightmost bit to check if it's 0 or 1.
// The == 1 compares the result to 1.
//check if stack b is not empty
//ensures that all numbers are in one place(stack a) 
//before checking the next bit.
//move to next bit position

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
