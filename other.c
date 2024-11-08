/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:56:43 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/08 03:50:49 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_cc(char *split_argc, t_stack **stacka)
{
	int		value;
	t_stack	*newnode;

	value = ft_atoi(split_argc);
	if (is_numeric(split_argc))
		return (ft_printf("Error\n"), 1);
	if (check_value(value) || check_duplicates(*stacka, value))
		return (ft_printf("Error\n"), 1);
	newnode = ft_lstnew(value);
	if (!newnode)
		return (ft_printf("Error\n"), 1);
	ft_stadd_back(stacka, newnode);
	return (0);
}

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
int	best_b(t_stack *stack, int nbr)
{
	int	f_nbr;

	f_nbr = find_max(stack);
	if (nbr > f_nbr)
	{
		f_nbr = find_min(stack);
		return (f_nbr);
	}
	if (nbr < find_min(stack))
	{
		f_nbr = find_min(stack);
		return (f_nbr);
	}
	while (stack)
	{
		if (stack->nbr > nbr && stack->nbr < f_nbr)
			f_nbr = stack->nbr;
		stack = stack->next;
	}
	return (f_nbr);
}
