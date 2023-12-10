/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:30:55 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/12/08 16:16:48 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

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
		stack->cpos = i;
		if (i <= center)
			stack->amedian = true;
		else
			stack->amedian = false;
		stack = stack->next;
		i++;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->cpos;
		if (!(b->amedian))
			b->price = len_b - (b->cpos);
		if (b->target->amedian)
			b->price = b->price + (b->target->cpos);
		else
			b->price = b->price + (len_a - b->target->cpos);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	best_value;
	t_stack	*best;

	if (b == NULL)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->price < best_value)
		{
			best_value = b->price;
			best = b;
		}
		b = b->next;
	}
	best->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
