/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:20:44 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 19:36:29 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("%d ", stack->nbr);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	create_stacka(int argc, char **argv, t_stack **stacka)
{
	int		i;
	int		j;
	char	**split_argc;

	i = 1;
	while (i < argc)
	{
		split_argc = ft_split(argv[i], ' ');
		j = 0;
		while (split_argc[j])
		{
			if (stack_cc(split_argc[j], stacka))
				return (1);
			j++;
		}
		i++;
	}
	free(split_argc);
	return (0);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
void	position_in_stack(t_stack *stack)
{
	int	position;
	int	median;

	median = (stack_size_f(stack) - 1) / 2;
	position = 0;
	while (stack)
	{
		stack->position = position;
		if (position <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		position++;
	}
}

void	sort_max_3(t_stack **stacka)
{
	t_stack	*highest;

	highest = find_max(*stacka);
	if (*stacka == highest)
		f_ra(stacka);
	else if ((*stacka)->next == highest)
		f_rra(stacka);
	if ((*stacka)->next->nbr < (*stacka)->nbr)
		f_sa(stacka);
}
