/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:09:35 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 18:02:02 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//from one stack to the other//
void	push(t_stack **dst, t_stack **src)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*dst == NULL)
	{
		*dst = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dst;
		*dst = node;
	}
}

void	pushb(t_stack **a, t_stack **b, int median)
{
	t_stack	*temp;

	temp = NULL;
	pb(b, a);
	temp = *b;
	if (temp->value < median)
		rb(b);
}

int	calculate_median(t_stack **a)
{
	t_stack	*list;
	t_stack	*templist;
	int		i;

	list = *a;
	templist = *a;
	while (templist)
	{
		i = 0;
		while (list)
		{
			if (templist->value > list->value)
				i++;
			list = list->next;
		}
		if (i == stack_len(*a) / 2)
			return (templist->value);
		list = *a;
		templist = templist->next;
	}
	return (0);
}
