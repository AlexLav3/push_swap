/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:09:47 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/24 17:31:47 by elavrich         ###   ########.fr       */
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
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		newnode = ft_lstnew(value);
		ft_stadd_back(&stacka, newnode);
		i++;
	}
	sa(&stacka);
	pb(&stacka, &stackb);
	ft_printf("\n%d\n", stackb->nbr);
	ft_printf("%d\n", stackb->next->nbr);
	ft_printf("%d\n", stackb->next->next->nbr);
}
