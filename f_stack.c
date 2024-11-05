/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:01:35 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/25 20:22:54 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

int	stack_size_f(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*ft_lstnew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

void	ft_stadd_back(t_stack **stacka, t_stack *new)
{
	t_stack	*current;

	if (!new || !stacka)
		return ;
	if (*stacka == NULL)
	{
		*stacka = new;
		return ;
	}
	current = *stacka;
	current = ft_lstlast(*stacka);
	current->next = new;
}

void	ft_stadd_front(t_stack **stacka, t_stack *new)
{
	new->next = *stacka;
	*stacka = new;
}
