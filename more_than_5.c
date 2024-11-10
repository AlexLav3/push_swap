/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:39:45 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/10 02:14:21 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_n(t_stack *stacka, t_stack *stackb)
{
	int	min_operations;
	int	cheapest_n;
	int	total_rotations;

	if (!stacka || !stackb)
		return (0);
	min_operations = INT_MAX;
	cheapest_n = best_b(stacka, stackb->nbr);
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

	if (!*stacka || !*stackb)
		return ;
	lowest_n = cheapest_n(*stacka, *stackb);
	while ((*stacka)->nbr != lowest_n)
	{
		if (position_in_stack(*stacka, lowest_n) <= stack_size_f(*stacka) / 2)
		{
			ra(stacka);
			ft_printf("ra\n");
		}
		else
		{
			rra(stacka);
			ft_printf("rra\n");
		}
	}
	if ((*stacka)->nbr == lowest_n)
		pb(stacka, stackb);
}

void	do_cheapest_m(t_stack **stacka, t_stack **stackb)
{
	char	*cheap_m;
	int		min_rotation;
	int		bb;

	if (!stacka)
		return ;
	while (stack_size_f(*stacka) > 1 && !is_sorted(*stacka))
	{
		if (*stackb)
			bb = best_b(*stacka, (*stackb)->nbr);
		cheap_m = cheapest_move(*stacka, *stackb);
		if (stack_size_f(*stacka) <= 5 && *stackb)
		{
			sort_max_5(stacka, stackb);
		}
		else
		{
			if (ft_strcmp(cheap_m, "rrr") == 0)
				rrr(stacka, stackb);
			else if (ft_strcmp(cheap_m, "ra") == 0)
			{
				ra(stacka);
				ft_printf("ra\n");
			}
			else if (ft_strcmp(cheap_m, "pb") == 0)
				pb(stacka, stackb);
			else if (ft_strcmp(cheap_m, "rb") == 0)
			{
				rb(stackb);
				ft_printf("rb\n");
				// ft_check(*stacka);
			}
			if (!is_sorted(*stacka) || !is_sorted(*stackb))
				push_lowest_n(stacka, stackb);
			// ft_printf("cheapest m: a ");
			// ft_check(*stacka);
			// ft_printf("cheapest m: b ");
			// ft_check(*stackb);
		}
	}
	bb = best_b(*stacka, (*stackb)->nbr);
	while (*stackb)
	{
		if (*stacka && (*stacka)->nbr == bb)
		{
			pa(stacka, stackb);
			if (*stackb)
				bb = best_b(*stacka, (*stackb)->nbr);
		}
		else if (*stacka && (*stacka)->nbr != bb)
		{
			ra(stacka);
			ft_printf("ra\n");
		}
		if (stack_size_f(*stacka) <= 1)
			break ;
	}
	while (!is_sorted(*stacka))
	{
		//ft_check(*stacka);
		ra(stacka);
		ft_printf("ra\n");
	}
}
