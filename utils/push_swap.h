/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:07:35 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/28 18:39:26 by pkovacs-         ###   ########.fr       */
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
	int				position;
	int				price;
	bool			above_center;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

//stack creation
int		ft_strlen(const char *str);
long	ft_atol(const char *str);
int		stack_len(t_stack *stack);
void	node_add_back(t_stack **stack, int nbr);
void	stack_create(t_stack **a, char **argv, bool freeargv);
char	**ft_split(char const *s, char c);

//node utils
void	set_target(t_stack *a, t_stack *b);
void	set_position(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	set_nodes(t_stack *a, t_stack *b);

//error handling
void	free_stack(t_stack **stack);
void	free_argv(char **argv);
int		error_format(char *str);
void	error(t_stack **a, char **argv, bool freeargv);
int		error_repetition(t_stack *a, int nbr);

//sorting
void	small_sort(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
bool	sorted(t_stack *stack);
void	push_swap(t_stack **a, t_stack **b);
void	push_nodes(t_stack **a, t_stack **b);
void	move_up(t_stack **stack, t_stack *cheapest, char name);

//finding nodes
t_stack	*find_last(t_stack *head);
t_stack	*find_onebefore_last(t_stack *head);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);

//commands
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sa(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	rrb(t_stack **b);
void	sb(t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);

//command utils
void	swap(t_stack **head);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **dst, t_stack **src);
void	pushb(t_stack **a, t_stack **b, int median);
int		calculate_median(t_stack **a);
void	push(t_stack **dst, t_stack **src);
void	pushb(t_stack **a, t_stack **b, int median);
int		calculate_median(t_stack **a);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

#endif