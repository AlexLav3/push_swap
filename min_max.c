/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:55:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/19 00:12:56 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;

	min_node = stack;
	while (stack)
	{
		if (stack->nbr < min_node->nbr)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;

	max_node = stack;
	while (stack)
	{
		if (stack->nbr > max_node->nbr)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	free_stack(t_stack **stack)
{
	t_stack	*st;
	t_stack	*next;

	st = *stack;
	while (st)
	{
		next = st->next;
		free(st);
		st = next;
	}
	*stack = NULL;
}

void	free_split(char **split_argc)
{
	int	i;

	i = 0;
	if (!split_argc)
		return ;
	while (split_argc[i])
	{
		free(split_argc[i]);
		i++;
	}
	free(split_argc);
}
