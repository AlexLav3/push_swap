/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:30:41 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/31 01:39:11 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stacka)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	first = *stacka;
	last = ft_lstlast(*stacka);
	tmp = first->next;
	last->next = *stacka;
	first->next = tmp;
	*stacka = last;
	ft_printf("rra\n");
}

void	rrb(t_stack **stackb)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	first = *stackb;
	last = ft_lstlast(*stackb);
	tmp = first->next;
	last->next = *stackb;
	first->next = tmp;
	*stackb = last;
	ft_printf("rrb\n");
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rra(stacka);
	rrb(stackb);
	ft_printf("rrr\n");
}
