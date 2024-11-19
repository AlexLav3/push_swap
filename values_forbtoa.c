/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_forbtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:42:11 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/19 00:28:29 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_bb_asc(t_stack *stacka, t_stack *stackb)
{
	t_stack	*c_a;
	t_stack	*push_pos;
	long	largest_smaller;

	push_pos = find_min(stacka);
	largest_smaller = LONG_MAX;
	while (stackb)
	{
		largest_smaller = LONG_MAX;
		c_a = stacka;
		while (c_a)
		{
			if (c_a->nbr > stackb->nbr && c_a->nbr < largest_smaller)
			{
				largest_smaller = c_a->nbr;
				push_pos = c_a;
			}
			c_a = c_a->next;
		}
		if (LONG_MAX == largest_smaller)
			stackb->push_pos = find_min(stacka);
		else
			stackb->push_pos = push_pos;
		stackb = stackb->next;
	}
}

void	price_b_to_a(t_stack *stacka, t_stack *stackb)
{
	int	l_a;
	int	l_b;

	if (!stackb || !stacka)
		return ;
	l_a = stack_size_f(stacka);
	l_b = stack_size_f(stackb);
	while (stackb)
	{
		stackb->price = stackb->position;
		if (!(stackb->above_median))
			stackb->price = l_b - (stackb->position);
		if (stackb->push_pos->above_median)
			stackb->price += stackb->push_pos->position;
		else
			stackb->price += l_a - (stackb->push_pos->position);
		stackb = stackb->next;
	}
}

t_stack	*cheapest_b(t_stack *stackb)
{
	if (NULL == stackb)
		return (NULL);
	while (stackb)
	{
		if (stackb->cheapest)
			return (stackb);
		stackb = stackb->next;
	}
	return (NULL);
}

void	cheapest_n_b(t_stack *stackb)
{
	long	best_n;
	t_stack	*best_node;

	if (stackb == NULL)
		return ;
	best_node = NULL;
	best_n = LONG_MAX;
	while (stackb)
	{
		if (stackb->price < best_n)
		{
			best_n = stackb->price;
			best_node = stackb;
		}
		stackb = stackb->next;
	}
	if (best_node)
		best_node->cheapest = 1;
}

void	set_values_btoa(t_stack *stacka, t_stack *stackb)
{
	position_in_stack(stacka);
	position_in_stack(stackb);
	set_bb_asc(stacka, stackb);
	price_b_to_a(stacka, stackb);
	cheapest_n_b(stackb);
}
