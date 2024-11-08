/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_calculations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:55:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/08 03:52:58 by elavrich         ###   ########.fr       */
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
	biggest_n = best_b(stack, nbr);
	ft_check(stack);
	while (stack && stack->nbr != biggest_n)
	{
		// ft_printf("%d\n", stack->nbr);
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
	int	cheap_n;
	int	forward_count;
	int	reverse_count;
	int	stack_size;

	stack_size = stack_size_f(stack);
	reverse_count = 0;
	forward_count = 0;
	cheap_n = best_b(stack, nbr);
	while (stack && stack->nbr != cheap_n)
	{
		// ft_printf("%d\n", stack->nbr);
		forward_count++;
		stack = stack->next;
	}
	reverse_count = stack_size - forward_count;
	if (forward_count < reverse_count)
		return (forward_count);
	else
		return (reverse_count);
}
char	*cheapest_move(t_stack *stacka, t_stack *stackb)
{
	int		b_rotations;
	int		a_rotations;
	char	*tot_op;

	ft_printf("a:");
	ft_check(stacka);
	ft_printf("b:");
	ft_check(stackb);
	b_rotations = calculate_b_rotations(stackb->nbr, stackb);
	a_rotations = calculate_a_rotations(stacka->nbr, stacka);
	if (a_rotations == b_rotations)
		tot_op = "rrr";
	else if (a_rotations > b_rotations)
		tot_op = "rb";
	else if (a_rotations < b_rotations)
		tot_op = "ra";
	return (tot_op);
}
