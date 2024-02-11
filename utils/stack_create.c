/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:00:59 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 18:39:09 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str && str[i] != '\0')
	{
		i++;
	}
	return (i);
}
// take out all white spaces (' ' (32), and 9-13)
// handle - and + signes
// deduct '0' (48) from the character to get integer
// if non digit character found the program stops

long	ft_atol(const char *str)
{
	int		i;
	long	neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while ((str[i] >= '0') && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
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

//adds a node the the end of the stack
//stack==NULL check if it points to invalid memory
//*stack == NULL check if the value pointed by the pointer is NULL
void	node_add_back(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last = find_last(*stack);
		last->next = node;
	}
}

//checks for errors in the string, converts it to long,
//runs function noda_add_back which creates a node and 
//appends it to the end of the stack
void	stack_create(t_stack **a, char **argv, bool freeargv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_format(argv[i]))
			error(a, argv, freeargv);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error(a, argv, freeargv);
		if (error_repetition(*a, (int)nbr))
			error(a, argv, freeargv);
		node_add_back(a, nbr);
		i++;
	}
	if (freeargv)
		free_argv(argv);
}
