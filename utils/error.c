/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:03:15 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 17:58:19 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//frees up the stack
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

//need to free it up because of the ft_split
void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

//if it's not number or +-
//if it is +- but next char is not number
//if it has any non numbers in the rest of the str
int	error_format(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	i++;
	while (str[i])
	{
		if ((!(str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
			return (1);
		i++;
	}
	return (0);
}

//frees up the stack and string
void	error(t_stack **a, char **argv, bool freeargv)
{
	free_stack(a);
	if (freeargv)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit (1);
}

//checks if the next value is the same as the current one
int	error_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
