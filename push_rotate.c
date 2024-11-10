/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:24 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/09 23:14:00 by elavrich         ###   ########.fr       */
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}

void	ra(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stacka || !(*stacka)->next)
		return ;
	//ft_check(*stacka);
	first = *stacka;
	*stacka = first->next;
	first->next = NULL;
	last = ft_lstlast(*stacka);
	last->next = first;
}

void	rb(t_stack **stackb)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (!*stackb || !(*stackb)->next)
		return ;
	first = *stackb;
	*stackb = first->next;
	first->next = NULL;
	last = ft_lstlast(*stackb);
	last->next = first;
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka);
	rb(stackb);
	ft_printf("rr\n");
}
