/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:20:44 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/06 16:50:08 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
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

int	get_abs(int nbr)
{
	if (nbr < 0)
	{
		return (nbr * -1);
	}
	return (nbr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
int	calculate_total_rotations(int nbr, t_stack *stacka, t_stack *stackb)
{
	int	a_rotations;
	int	b_rotations;

	a_rotations = calculate_a_rotations(nbr, stacka);
	b_rotations = calculate_b_rotations(nbr, stackb);
	if (a_rotations == b_rotations)
		return (a_rotations);
	return (a_rotations + b_rotations);
}
int	position_in_stack(t_stack *stack, int nbr)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->nbr == nbr)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}
