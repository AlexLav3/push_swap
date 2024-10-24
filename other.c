/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:56:43 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/25 01:33:21 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_value(int i)
{
	if (i < INT_MIN || i > INT_MAX)
		return (1);
	return (0);
}

int	check_duplicates(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->nbr == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
