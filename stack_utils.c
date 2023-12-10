/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:13:07 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/12/09 19:07:01 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks the whole stack and compares if the value of each node is higher than
//long biggest - innitially the lowest possible number. 
//When checked the whole stack, returns the one with higherst value
t_stack	*find_biggest(t_stack *stack)
{
	long	biggest;
	t_stack	*biggest_node;

	biggest_node = NULL;
	if (stack == NULL)
		return (NULL);
	biggest = LONG_MIN;
	while (stack)
	{
		if (stack->value > biggest)
		{
			biggest = stack->value;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

//cheks the whole stack and compares if the value of each node is lower than
//long smallest - innitially the highest possible number.
//When checked the whole stack, returns the one with lowest value.
t_stack	*find_smallest(t_stack *stack)
{
	long	smallest;
	t_stack	*smallest_node;

	smallest_node = NULL;
	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

//returns the stack where the cheapest bool is true
t_stack	*find_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//checks the lenght of the stack
int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
