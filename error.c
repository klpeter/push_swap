/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:03:15 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/12/09 16:12:03 by pkovacs-         ###   ########.fr       */
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
void	free_argument(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
}

//if it's not number or +-
//if it is +- but next char is not number
//if it has any non numbers in the rest of the str
int	error_format(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*str)
	{
		if (!(*str >= '0' || *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

//frees up the stack and string
void	error_free(t_stack **a, char **argv, bool checker)
{
	free_stack(a);
	if (checker)
		free_argument(argv);
	write(2, "Error\n", 6);
	exit (1);
}

//checks if the next value is the same as the current one
int	error_repetition(t_stack *a, long nbr)
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
