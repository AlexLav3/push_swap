/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:11:53 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/04 23:29:14 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_stack **stacka, t_stack **stackb)
{
	int	min_val;

	if (!*stacka || !(*stacka)->next)
		return ;
	min_val = find_min(*stacka);
	while ((*stacka)->nbr != min_val)
		ra(stacka);
	pb(stacka, stackb);
}

void	sort_max_5(t_stack **stacka, t_stack **stackb)
{
	if (!stackb)
		return ;
	while (stack_size_f(*stacka) > 1)
		push_min(stacka, stackb);
	while (*stackb)
		push_all(stackb, stacka);
}
