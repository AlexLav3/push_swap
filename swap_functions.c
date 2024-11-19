/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:38:10 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/18 23:37:05 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*second;

	first = *stacka;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stacka = second;
}

void	sb(t_stack **stackb)
{
	t_stack	*first;
	t_stack	*second;

	first = *stackb;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stackb = second;
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	sa(stacka);
	sb(stackb);
}

void	f_rrr(t_stack **stacka, t_stack **stackb)
{
	rrr(stacka, stackb);
	position_in_stack(*stacka);
	position_in_stack(*stackb);
	ft_printf("rrr\n");
}
