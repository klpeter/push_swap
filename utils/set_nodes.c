/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:30:55 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 18:04:19 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*looks for a number in stack A that is the closest to the number in stack B
if nothing is found then it will look for the smallest number in stack A and
set it as a target for the node in the stack B*/
void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	int		min;

	while (b)
	{
		min = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < min)
			{
				min = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (min == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

/*checks if a number in the stack is above the center or below, if above
sets amedian true*/
void	set_position(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	if (stack == NULL)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= center)
			stack->above_center = true;
		else
			stack->above_center = false;
		stack = stack->next;
		i++;
	}
}

/*sets the price of each node - how many commands are needed to move it*/
void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->position;
		if (!(b->above_center))
			b->price = len_b - (b->position);
		if (b->target->above_center)
			b->price = b->price + (b->target->position);
		else
			b->price = b->price + (len_a - b->target->position);
		b = b->next;
	}
}

/*looks for the node where the price is the lowest, when found sets the
cheapest bool true*/
void	set_cheapest(t_stack *b)
{
	int		min;
	t_stack	*best;

	if (b == NULL)
		return ;
	min = INT_MAX;
	while (b)
	{
		if (b->price < min)
		{
			min = b->price;
			best = b;
		}
		b->cheapest = false;
		b = b->next;
	}
	best->cheapest = true;
}

void	set_nodes(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
