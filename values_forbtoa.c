/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values_forbtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:42:11 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 02:43:33 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_asc(t_stack *stacka, t_stack *stackb)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	largest_smaller;

	target_node = find_min(stacka);
	largest_smaller = LONG_MAX;
	while (stackb)
	{
		largest_smaller = LONG_MAX;
		current_a = stacka;
		while (current_a)
		{
			if (current_a->nbr > stackb->nbr
				&& current_a->nbr < largest_smaller)
			{
				largest_smaller = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == largest_smaller)
			stackb->target_node = find_min(stacka);
		else
			stackb->target_node = target_node;
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
		if (stackb->target_node->above_median)
			stackb->price += stackb->target_node->position;
		else
			stackb->price += l_a - (stackb->target_node->position);
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
	set_target_asc(stacka, stackb);
	price_b_to_a(stacka, stackb);
	cheapest_n_b(stackb);
}
