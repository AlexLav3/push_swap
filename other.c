/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:56:43 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/24 22:21:52 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_value(int i)
{
	if (i < INT_MIN || i > INT_MAX)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	check_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->nbr == value)
		{
			ft_printf("Error \n");
			return (1);
		}
		stack = stack->next;
	}
	return (0);
}
