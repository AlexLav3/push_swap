/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:30:41 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/16 00:39:12 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stacka)
{
	t_stack	*tmp;
	int		i;

	if (!*stacka || !(*stacka)->next)
		return ;
	i = 0;
	tmp = *stacka;
	while ((*stacka)->next)
	{
		i++;
		*stacka = (*stacka)->next;
	}
	(*stacka)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	rrb(t_stack **stackb)
{
	t_stack	*tmp;
	int		i;

	if (!*stackb || !(*stackb)->next)
		return ;
	i = 0;
	tmp = *stackb;
	while ((*stackb)->next)
	{
		i++;
		*stackb = (*stackb)->next;
	}
	(*stackb)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka);
	rrb(stackb);
}
