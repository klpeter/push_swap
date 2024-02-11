/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findingnodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:47:22 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 17:48:12 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//returns the last node
t_stack	*find_last(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack	*find_onebefore_last(t_stack *head)
{
	if (head == NULL || head->next == NULL)
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}

//checks the whole stack and compares if the value of each node is higher than
//long biggest - innitially the lowest possible number. 
//When checked the whole stack, returns the one with higherst value
t_stack	*find_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*biggest_node;

	biggest_node = NULL;
	if (stack == NULL)
		return (NULL);
	biggest = INT_MIN;
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
	int		smallest;
	t_stack	*smallest_node;

	smallest_node = NULL;
	if (stack == NULL)
		return (NULL);
	smallest = INT_MAX;
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
