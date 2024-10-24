/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_rp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:24 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/24 17:32:33 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				pa(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	tmp = *stackb;
	*stackb = tmp->next;
	tmp->next = *stacka;
	*stacka = tmp;
}
void				pb(t_stack **stacka, t_stack **stackb)
{
	t_stack *tmp;

	tmp = *stacka;
	*stacka = tmp->next;
	tmp->next = *stacka;
	*stackb = tmp;
}
// void	ra(t_stack **stacka)
// {
// }
// void	rb(t_stack **stackb)
// {
// }
