/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:09:47 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/07 02:20:13 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;
	t_stack	*sorted_stack;
	int		stacka_size;
	int		min_operations;
	int		push_count;
	int		nbr;

	sorted_stack = NULL;
	stacka = NULL;
	stackb = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (create_stacka(argc, argv, &stacka))
		return (0);
	stacka_size = stack_size_f(stacka);
	i++;
	push_count = 0;
	while (push_count < 2 && stacka != NULL)
	{
		pb(&stacka, &stackb);
		push_count++;
	}
	ft_check(stackb);
	do_cheapest_m(&stacka, &stackb);
	//ft_check(stacka);
	//  ft_check(stackb);
	return (0);
}
