/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_operations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:36:42 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 23:37:29 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_ra(t_stack **stacka)
{
	ra(stacka);
	position_in_stack(*stacka);
	ft_printf("ra\n");
}

void	f_rb(t_stack **stackb)
{
	rb(stackb);
	position_in_stack(*stackb);
	ft_printf("rb\n");
}

void	f_rr(t_stack **stacka, t_stack **stackb)
{
	rr(stacka, stackb);
	position_in_stack(*stacka);
	position_in_stack(*stackb);
	ft_printf("rr\n");
}

void	f_rra(t_stack **stacka)
{
	rra(stacka);
	position_in_stack(*stacka);
	ft_printf("rra\n");
}

void	f_rrb(t_stack **stackb)
{
	rrb(stackb);
	position_in_stack(*stackb);
	ft_printf("rrb\n");
}
