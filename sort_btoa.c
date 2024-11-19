/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:50:54 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 23:27:12 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_sort(t_stack **stacka, t_stack **stackb)
{
	t_stack	*cheapest_node;

	cheapest_node = cheapest_b(*stackb);
	while (*stackb != cheapest_node && *stacka != cheapest_node->push_pos)
	{
		if (cheapest_node->above_median
			&& cheapest_node->push_pos->above_median)
			f_rr(stacka, stackb);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->push_pos->above_median))
			f_rrr(stacka, stackb);
		else
			break ;
	}
}

void	move_to_a(t_stack **stacka, t_stack **stackb)
{
	t_stack	*cheapest_node;

	cheapest_node = cheapest_b(*stackb);
	initial_sort(stacka, stackb);
	while (*stackb != cheapest_node)
	{
		if (cheapest_node->above_median)
			f_rb(stackb);
		else
			f_rrb(stackb);
	}
	while (*stacka != cheapest_node->push_pos)
	{
		if (cheapest_node->push_pos->above_median)
			f_ra(stacka);
		else
			f_rra(stacka);
	}
	f_pa(stacka, stackb);
}
