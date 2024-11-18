/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:24 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/16 00:38:57 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (*stackb == NULL)
		return ;
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = *stacka;
	*stacka = tmp;
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	if (*stacka == NULL)
		return ;
	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = *stackb;
	*stackb = tmp;
}

void	ra(t_stack **stacka)
{
	t_stack	*tmp;

	if (!*stacka || !(*stacka)->next)
		return ;
	tmp = *stacka;
	*stacka = ft_lstlast(*stacka);
	(*stacka)->next = tmp;
	*stacka = tmp->next;
	tmp->next = NULL;
}

void	rb(t_stack **stackb)
{
	t_stack	*tmp;

	if (!*stackb || !(*stackb)->next)
		return ;
	tmp = *stackb;
	*stackb = ft_lstlast(*stackb);
	(*stackb)->next = tmp;
	*stackb = tmp->next;
	tmp->next = NULL;
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka);
	rb(stackb);
}
