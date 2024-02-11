/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:09:12 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/26 20:18:14 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*if the top element is the largest, then it moves the top element to the bottom
(ra), if the second element is the largest, then moves the bottom elemnt to the
top (rra), then it checks if the first element is larger than the second one, if
so then it swaps the first two elements (sa)*/
void	small_sort(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_biggest(*a);
	if (*a == biggest)
		ra(a);
	else if ((*a)->next == biggest)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		set_nodes(*a, *b);
		move_up(a, find_smallest(*a), 'a');
		pb(b, a);
	}
}

bool	sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
