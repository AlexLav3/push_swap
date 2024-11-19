/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:28:24 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/19 00:29:30 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1)
		return (0);
	if (create_stacka(argc, argv, &stacka))
	{
		free_stack(&stacka);
		return (0);
	}
	if (is_sorted(stacka))
		return (0);
	push_swap(&stacka, &stackb);
	free_stack(&stacka);
	free_stack(&stackb);
	return (0);
}
