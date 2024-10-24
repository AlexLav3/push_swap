/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:09:47 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/24 19:16:33 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_stack	*newnode;
	int		i;
	int		value;

	stacka = NULL;
	stackb = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (check_value(value) || check_duplicates(stacka, value))
			return (0);
		newnode = ft_lstnew(value);
		if (!newnode)
		{
			return (ft_printf("Error\n"), 0);
		}
		ft_stadd_back(&stacka, newnode);
		i++;
	}
	ft_printf("%d\n", stacka->nbr);
	ft_printf("%d\n", stacka->next->nbr);
	ft_printf("%d\n", stacka->next->next->nbr);
	return (0);
}
