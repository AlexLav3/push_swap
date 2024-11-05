/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_calculations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:55:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/05 00:19:24 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	calculate_b_rotations(int nbr, t_stack *stack)
{
	int	biggest_n;
	int	forward_count;
	int	reverse_count;
	int	stack_size;

	stack_size = stack_size_f(stack);
	reverse_count = 0;
	forward_count = 0;
	biggest_n = find_max(stack);
	while (stack->nbr != biggest_n)
	{
		if (stack->nbr == biggest_n)
			break ;
		forward_count++;
		stack = stack->next;
	}
	reverse_count = stack_size - forward_count;
	if (forward_count < reverse_count)
		return (forward_count);
	else
		return (reverse_count);
}

int	calculate_a_rotations(int nbr, t_stack *stack)
{
	int	smallest_n;
	int	forward_count;
	int	reverse_count;
	int	stack_size;

	stack_size = stack_size_f(stack);
	reverse_count = 0;
	forward_count = 0;
	smallest_n = find_min(stack);
	while (stack)
	{
		if (stack->nbr == smallest_n)
			break ;
		forward_count++;
		stack = stack->next;
	}
	reverse_count = stack_size - forward_count;
	if (forward_count < reverse_count)
		return (forward_count);
	else
		return (reverse_count);
}
int	cheapest_move(t_stack *stacka, t_stack *stackb)
{
	int	min_op;
	int	cheapest_n;
	int	nbr;
	int	b_rotations;
	int	a_rotations;
	int	tot_op;

	tot_op = 0;
	nbr = stacka->nbr;
	min_op = INT_MAX;
	cheapest_n = 0;
	while (stacka)
	{
		nbr = stacka->nbr;
		b_rotations = calculate_b_rotations(nbr, stackb);
		a_rotations = calculate_a_rotations(nbr, stacka);
		if (a_rotations == b_rotations)
			tot_op = a_rotations;
		else
			tot_op = a_rotations + b_rotations;
		if (tot_op < min_op)
		{
			min_op = tot_op;
			cheapest_n = nbr;
		}
		stacka = stacka->next;
	}
	return (min_op);
}
