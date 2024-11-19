/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_push_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:33:29 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 23:37:46 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_sa(t_stack **stacka)
{
	sa(stacka);
	position_in_stack(*stacka);
	ft_printf("sa\n");
}

void	f_sb(t_stack **stackb)
{
	sb(stackb);
	position_in_stack(*stackb);
	ft_printf("sb\n");
}

void	f_ss(t_stack **stacka, t_stack **stackb)
{
	ss(stacka, stackb);
	position_in_stack(*stackb);
	position_in_stack(*stacka);
	ft_printf("ss\n");
}

void	f_pa(t_stack **stacka, t_stack **stackb)
{
	pa(stacka, stackb);
	ft_printf("pa\n");
}

void	f_pb(t_stack **stacka, t_stack **stackb)
{
	pb(stacka, stackb);
	ft_printf("pb\n");
}
