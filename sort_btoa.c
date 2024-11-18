/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:50:54 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 20:08:36 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a(t_stack **stacka, t_stack **stackb)
{
	t_stack	*cheapest_node;

	cheapest_node = cheapest_b(*stackb);
	while (*stackb != cheapest_node && *stacka != cheapest_node->target_node)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
		{
			f_rr(stacka, stackb);
		}
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
		{
			f_rrr(stacka, stackb);
		}
		else
			break ;
	}
	while (*stackb != cheapest_node)
	{
		if (cheapest_node->above_median)
			f_rb(stackb);
		else
			f_rrb(stackb);
	}
	while (*stacka != cheapest_node->target_node)
	{
		if (cheapest_node->target_node->above_median)
			f_ra(stacka);
		else
			f_rra(stacka);
	}
	f_pa(stacka, stackb);
}
