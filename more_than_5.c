/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:39:45 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/08 03:54:15 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_n(t_stack *stacka, t_stack *stackb)
{
	int	min_operations;
	int	cheapest_n;
	int	total_rotations;

	min_operations = INT_MAX;
	cheapest_n = stacka->nbr;
	total_rotations = calculate_total_rotations(stacka->nbr, stacka, stackb);
	while (stacka)
	{
		total_rotations = calculate_total_rotations(stacka->nbr, stacka,
				stackb);
		if (total_rotations < min_operations)
		{
			min_operations = total_rotations;
			cheapest_n = stacka->nbr;
		}
		stacka = stacka->next;
	}
	return (cheapest_n);
}

void	push_lowest_n(t_stack **stacka, t_stack **stackb)
{
	int	lowest_n;
	int	nbr;

	lowest_n = cheapest_n(*stackb, *stacka);
	if (*stacka == NULL)
		return ;
	while ((*stacka)->nbr != lowest_n)
	{
		lowest_n = cheapest_n(*stackb, *stacka);
		if (position_in_stack(*stacka, lowest_n) <= stack_size_f(*stacka) / 2)
			ra(stacka);
		else
			rra(stacka);
	}
	if ((*stacka)->nbr == lowest_n)
		pb(stacka, stackb);
	else
		ft_printf("Error: lowest_n not found in stacka\n");
	ft_printf("push_lowest b ");
	ft_check(*stackb);
	ft_printf("push_lowest stacka: ");
	ft_check(*stacka);
}

void	do_cheapest_m(t_stack **stacka, t_stack **stackb)
{
	char	*cheap_m;
	int		min_rotation;
	int		bb;

	while (!is_sorted(*stacka))
		push_lowest_n(stacka, stackb);
	while (*stacka)
	{
		cheap_m = cheapest_move(*stacka, *stackb);
		if (ft_strcmp(cheap_m, "rrr") == 0)
		{
			rrr(stacka, stackb);
			ft_printf("rrr\n");
		}
		else if (ft_strcmp(cheap_m, "ra") == 0)
			ra(stacka);
		else if (ft_strcmp(cheap_m, "rb") == 0)
			rb(stackb);
		if (!is_sorted(*stacka))
			push_lowest_n(stacka, stackb);
	}
	while (stack_size_f(*stackb) > 2)
	{
		if (!*stacka || (*stackb)->nbr < (*stacka)->nbr)
			pa(stacka, stackb);
		else
			ra(stacka);
	}
	bb = best_b(*stacka, (*stackb)->nbr);
	while (*stackb)
	{
		if ((*stacka)->nbr == bb)
		{
			pa(stacka, stackb);
			if (*stackb)
				bb = best_b(*stacka, (*stackb)->nbr);
		}
		else
			ra(stacka);
		if (stack_size_f(*stacka) == 1)
			break ;
	}
	while (!is_sorted(*stacka))
		ra(stacka);
}
