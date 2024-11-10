/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:42:36 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/09 21:36:32 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/src/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int					best_b(t_stack *stack, int nbr);

int					calculate_b_rotations(int nbr, t_stack *stack);
int					calculate_a_rotations(int nbr, t_stack *stack);
int					find_max(t_stack *stack);
char				*cheapest_move(t_stack *stacka, t_stack *stackb);
void				do_cheapest_m(t_stack **stacka, t_stack **stackb);
void				push_lowest_n(t_stack **stacka, t_stack **stackb);
int					cheapest_n(t_stack *stacka, t_stack *stackb);
int					get_abs(int nbr);
int					calculate_total_rotations(int nbr, t_stack *stacka,
						t_stack *stackb);
int					position_in_stack(t_stack *stack, int nbr);

int					is_sorted(t_stack *stack);
int					is_sorted_rev(t_stack *stack);

void				ft_check(t_stack *stack);
int					create_stacka(int argc, char **argv, t_stack **stacka);

int					check_value(int i);
int					check_duplicates(t_stack *stack, int value);
int					stack_cc(char *split_argc, t_stack **stacka);
int					is_numeric(const char *str);
void				sa(t_stack **stacka);
void				sb(t_stack **stackb);
void				ss(t_stack **stacka, t_stack **stackb);
void				pa(t_stack **stacka, t_stack **stackb);
void				pb(t_stack **stacka, t_stack **stackb);
void				ra(t_stack **stacka);
void				rb(t_stack **stackb);
void				rr(t_stack **stacka, t_stack **stackb);
void				rra(t_stack **stacka);
void				rrb(t_stack **stackb);
void				rrr(t_stack **stacka, t_stack **stackb);

int					stack_size_f(t_stack *stack);
void				ft_stadd_back(t_stack **stacka, t_stack *new);
void				ft_stadd_front(t_stack **stacka, t_stack *new);

int					find_min(t_stack *stack);
void				push_min(t_stack **stacka, t_stack **stackb);
void				sort_max_5(t_stack **stacka, t_stack **stackb);

t_stack				*ft_lstlast(t_stack *stack);
t_stack				*ft_lstnew(int nbr);

int					ft_strcmp(char *s1, char *s2);

#endif
