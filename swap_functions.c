/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:38:10 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/23 16:44:09 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stacka)
{
	t_stack	*tmpnbr;
	t_stack	*tmpnbr2;

	tmpnbr2 = stacka->nbr;
	tmpnbr = stacka->next;
}
void	sb(t_stack **stackb)
{
	t_stack	*tmpnbr;
	t_stack	*tmpnbr2;

	tmpnbr2 = stackb->nbr;
	tmpnbr = stackb->next;
}
void	ss(t_stack **stacka, t_stack **stackb)
{
	sa(**stacka);
	sb(**stackb);
}
