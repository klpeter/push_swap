/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:00:59 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/12/10 15:24:08 by pkovacs-         ###   ########.fr       */
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

//adds a node the the end of the stack
//stack==NULL check if it points to invalid memory
//*stack == NULL check if the value pointed by the pointer is NULL
void	node_add_back(t_stack **stack, long nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

//checks for errors in the string, converts it to long,
//runf function noda_add_back which creates a node and 
//appends it to the end of the stack
void	stack_create(t_stack **a, char **argv, bool checker, int argc)
{
	long	nbr;
	int		i;

	i = 0;
	if (argc == 2)
		i = -1;
	while (argv[i])
	{
		if (error_format(argv[i]))
			error_free(a, argv, checker);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, checker);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, checker);
		node_add_back(a, (int)nbr);
		i++;
	}
	if (checker)
		free_argument(argv);
}
