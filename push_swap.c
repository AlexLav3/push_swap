/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:09:47 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 23:36:56 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stacka, t_stack **stackb)
{
	int		stacka_size;
	t_stack	*lowest;

	stacka_size = stack_size_f(*stacka);
	if (stacka_size == 3)
	{
		sort_max_3(stacka);
		return ;
	}
	while (stack_size_f(*stacka) > 3)
		f_pb(stacka, stackb);
	sort_max_3(stacka);
	move_to_a_in_chunks(stacka, stackb);
	lowest = find_min(*stacka);
	while (*stacka != lowest)
	{
		if (lowest->above_median)
			f_ra(stacka);
		else
			f_rra(stacka);
	}
}

void	move_to_a_in_chunks(t_stack **stacka, t_stack **stackb)
{
	int		chunk_size;
	t_stack	*chunk_end;
	t_stack	*current_b;

	chunk_size = 4;
	current_b = *stackb;
	while (*stackb)
	{
		chunk_end = get_chunk_end(current_b, chunk_size);
		while (current_b != chunk_end && current_b)
		{
			set_values_btoa(*stacka, *stackb);
			move_to_a(stacka, stackb);
			current_b = *stackb;
		}
		if (*stackb)
			current_b = *stackb;
	}
}

t_stack	*get_chunk_end(t_stack *current_b, int chunk_size)
{
	int		count;
	t_stack	*chunk_end;

	count = 0;
	chunk_end = current_b;
	while (chunk_end && count < chunk_size)
	{
		chunk_end = chunk_end->next;
		count++;
	}
	return (chunk_end);
}
