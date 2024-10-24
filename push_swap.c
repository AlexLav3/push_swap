/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:09:47 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/25 00:43:37 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_create(char *split_argc, t_stack **stacka)
{
	int		value;
	t_stack	*newnode;

	value = ft_atoi(split_argc);
	if (check_value(value) || check_duplicates(*stacka, value))
		return (1);
	newnode = ft_lstnew(value);
	if (!newnode)
		return (ft_printf("Error\n"), 1);
	ft_stadd_back(stacka, newnode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	int		i;
	int		j;
	char	**split_argc;

	stacka = NULL;
	stackb = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		split_argc = ft_split(argv[i], ' ');
		j = 0;
		while (split_argc[j])
		{
			if (stack_create(split_argc[j], &stacka) == 1)
				return (0);
			j++;
		}
		i++;
	}
	// rra(&stacka);
	ft_printf("%d\n", stacka->nbr);
	ft_printf("%d\n", stacka->next->nbr);
	ft_printf("%d\n", stacka->next->next->nbr);
	// ft_printf("%d\n", stacka->next->next->next->nbr);
	return (0);
}
