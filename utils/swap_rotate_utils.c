/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:44:26 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 18:06:54 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first two elements in the stack, do nothnig if 1 or 0 element
void	swap(t_stack **head)
{
	t_stack	*temp;

	if ((*head) == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = temp->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
}

//takes the first node from the top and moves it to the bottom as last node//
void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = find_last(*stack);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

/*takes the last node and moves it to the top as the first node*/
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*onebefore;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = find_last(*stack);
	onebefore = find_onebefore_last(*stack);
	last->next = *stack;
	*stack = last;
	onebefore->next = NULL;
}

/*rotates stack A and B until the first node in A is not the target of the
chapest node, and the first node in the stack be is not the cheapest, then
updates the position of both stacks*/
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	set_position(*a);
	set_position(*b);
}

/*reverse rotates stack A and B until the first node in A is not the target of
the cheapest node, and the first node in stack B is not the cheapest node, then
updates the position of both stacks */
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	set_position(*a);
	set_position(*b);
}
