/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:33:17 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 18:07:18 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotates the stack until the topnode is at the top of the stack*/
void	move_up(t_stack **stack, t_stack *cheapest, char name)
{
	while (*stack != cheapest)
	{
		if (name == 'a')
		{
			if (cheapest->above_center)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (cheapest->above_center)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/*rotate_both and reverse_rotate_both are for simultaneusly manipulate the 
stacks this way to reduce the number of commands, while finish_rotation is
to make sure that the cheapest and target node are at the top of the stacks
(moved individualy) otherwise more commands would have needed*/
void	push_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->above_center && cheapest->target->above_center)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_center) && !(cheapest->target->above_center))
		reverse_rotate_both(a, b, cheapest);
	move_up(b, cheapest, 'b');
	move_up(a, cheapest->target, 'a');
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len_a;
	int		median;

	len_a = stack_len(*a);
	median = calculate_median(a);
	if (len_a == 5)
		sort_five(a, b);
	else
		while (len_a-- > 3)
			pushb(a, b, median);
	small_sort(a);
	while (*b)
	{
		set_nodes(*a, *b);
		push_nodes(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_center)
		while (*a != smallest)
			ra(a);
	else
		while (*a != smallest)
			rra(a);
}
