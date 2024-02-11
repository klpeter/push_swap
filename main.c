/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:22:39 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 18:14:24 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/push_swap.h"

//1. argc is the name of the program
//2. argc is a string
//if " numbers " then ft_split to split the numbers to separate strings 
//checker is true when split function was used to free the strings 
//after stack_create.

static void	remove_white_spaces(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '\0')
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	while (argv[i])
	{
		if (argv[i] >= 9 && argv[i] <= 13)
			argv[i] = ' ';
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		remove_white_spaces(argv[1]);
		argv = ft_split(argv[1], ' ');
		stack_create(&a, argv, true);
	}
	else
		stack_create(&a, argv + 1, false);
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			small_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
