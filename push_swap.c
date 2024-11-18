/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:09:47 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 20:08:41 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stacka;
	t_stack	*stackb;
	int		stacka_size;
	t_stack	*lowest;

	stacka = NULL;
	stackb = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (create_stacka(argc, argv, &stacka))
		return (0);
	stacka_size = stack_size_f(stacka);
	i++;
	if (stacka_size == 3)
	{
		sort_max_3(&stacka);
		return (0);
	}
	while (stack_size_f(stacka) > 3)
		f_pb(&stacka, &stackb);
	sort_max_3(&stacka);
	while (stackb)
	{
		set_values_btoa(stacka, stackb);
		move_to_a(&stacka, &stackb);
	}
	lowest = find_min(stacka);
	while (stacka != lowest)
	{
		if (lowest->above_median)
			f_ra(&stacka);
		else
			f_rra(&stacka);
	}
	return (0);
}
