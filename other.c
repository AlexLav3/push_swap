/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:56:43 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/02 00:02:42 by elavrich         ###   ########.fr       */
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

void	push_all(t_stack **stacka, t_stack **stackb)
{
	while (*stacka)
		pb(stacka, stackb);
}
void	add_to_list(t_stack **list, int nbr)
{
	t_stack	*temp;

	t_stack *new = ft_lstnew(nbr);
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
	}
	else
	{
		temp = *list;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
