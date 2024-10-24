/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:07:24 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/24 22:22:04 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	tmp = *stackb;
	*stackb = tmp->next;
	tmp->next = *stacka;
	*stacka = tmp;
	ft_printf("pa\n");
}

void	pb(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	tmp = *stacka;
	*stacka = tmp->next;
	tmp->next = *stacka;
	*stackb = tmp;
	ft_printf("pb\n");
}

void	ra(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	first = *stacka;
	tmp = first->next;
	last = ft_lstlast(*stacka);
	last->next = first;
	first->next = last;
	*stacka = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack **stackb)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	first = *stackb;
	tmp = first->next;
	last = ft_lstlast(*stackb);
	last->next = first;
	first->next = last;
	*stackb = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ra(stacka);
	rb(stackb);
	ft_printf("rr\n");
}
