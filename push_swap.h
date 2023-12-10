/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:07:35 by pkovacs-          #+#    #+#             */
/*   Updated: 2023/12/10 15:19:49 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				cpos;
	int				fpos;
	int				price;
	bool			amedian;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//error handling//
void	free_stack(t_stack **stack);
void	free_argument(char **argv);
int		error_format(char *str);
void	error_free(t_stack **a, char **argv, bool checker);
int		error_repetition(t_stack *a, long nbr);

//commands/
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

//stack utis//
t_stack	*find_last(t_stack *head);
void	node_add_back(t_stack **stack, long nbr);
void	stack_create(t_stack **a, char **argv, bool checker, int argc);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
int		stack_len(t_stack *stack);
char	**ft_split(char const *s, char c);
long	ft_atol(const char *str);
int		ft_strlen(const char *str);

//sort//
void	small_sort(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
bool	sorted(t_stack *stack);
void	finish_rotation(t_stack **stack, t_stack *topnode, char name);
void	move_nodes(t_stack **a, t_stack **b);
void	push_swap(t_stack **a, t_stack **b);
void	set_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);

#endif