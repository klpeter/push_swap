/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:22:39 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/12/10 15:24:12 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//1. argc is the name of the program
//2. argc is a string
//if " numbers " then ft_split to split the numbers to separate strings 
//checker is true when split function was used to free the strings 
//after stack_create.
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_create(&a, argv + 1, true, argc);
	}
	else
		stack_create(&a, argv + 1, false, argc);
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			small_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
