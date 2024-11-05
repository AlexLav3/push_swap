/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:20:44 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/04 23:54:55 by elavrich         ###   ########.fr       */
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
