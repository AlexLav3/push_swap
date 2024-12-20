/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:42:36 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/19 00:36:52 by elavrich         ###   ########.fr       */
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
	int				position;
	int				price;
	int				above_median;
	int				cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*push_pos;

}					t_stack;

void				free_stack(t_stack **stack);
void				free_split(char **split_argc);

// main functions
void				push_swap(t_stack **stacka, t_stack **stackb);
void				initial_sort(t_stack **stacka, t_stack **stackb);
void				move_to_a_in_chunks(t_stack **stacka, t_stack **stackb);
t_stack				*get_chunk_end(t_stack *current_b, int chunk_size);

// setting values
void				price_b_to_a(t_stack *stacka, t_stack *stackb);
t_stack				*cheapest_b(t_stack *stackb);
void				set_values_btoa(t_stack *stacka, t_stack *stackb);
void				move_to_a(t_stack **stacka, t_stack **stackb);
void				cheapest_n_b(t_stack *stackb);
void				set_bb_asc(t_stack *stacka, t_stack *stackb);
void				position_in_stack(t_stack *stacka);

// min and max
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);

// helper
void				ft_check(t_stack *stack);
int					is_sorted(t_stack *stack);

// sorting 3
void				sort_max_3(t_stack **stacka);

// starting functions
int					create_stacka(int argc, char **argv, t_stack **stacka);
int					check_value(int i);
int					check_duplicates(t_stack *stack, int value);
int					stack_cc(char *split_argc, t_stack **stacka);
int					is_numeric(const char *str);

// operations
void				f_sa(t_stack **stacka);
void				f_sb(t_stack **stackb);
void				f_ss(t_stack **stacka, t_stack **stackb);
void				f_pa(t_stack **stacka, t_stack **stackb);
void				f_pb(t_stack **stacka, t_stack **stackb);
void				f_ra(t_stack **stacka);
void				f_rb(t_stack **stackb);
void				f_rr(t_stack **stacka, t_stack **stackb);
void				f_rra(t_stack **stacka);
void				f_rrb(t_stack **stackb);
void				f_rrr(t_stack **stacka, t_stack **stackb);

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

// list functions
int					stack_size_f(t_stack *stack);
void				ft_stadd_back(t_stack **stacka, t_stack *new);
void				ft_stadd_front(t_stack **stacka, t_stack *new);
t_stack				*ft_lstlast(t_stack *stack);
t_stack				*ft_lstnew(int nbr);

#endif
