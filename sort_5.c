/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:11:53 by elavrich          #+#    #+#             */
/*   Updated: 2024/11/10 02:15:09 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_min(t_stack **stacka, t_stack **stackb)
// {
// 	int	min_val;

// 	if (!*stacka || !(*stacka)->next)
// 		return ;
// 	min_val = best_b(*stacka, (*stackb)->nbr);
// 	while ((*stacka)->nbr != min_val)
// 	{
// 		min_val = best_b(*stacka, (*stackb)->nbr);
// 		ra(stacka);
// 		ft_printf("stack a:");
// 		ft_check(*stacka);
// 		ft_printf("ra\n");
// 	}
// 	pb(stacka, stackb);
// }

void	sort_max_5(t_stack **stacka, t_stack **stackb)
{
	int	bb;

	if (!*stacka || !(*stacka)->next)
		return ;
	bb = best_b(*stacka, (*stackb)->nbr);
	while (!is_sorted(*stacka))
	{
		if (*stacka && (*stacka)->nbr == bb)
		{
			pb(stacka, stackb);
			if (*stackb)
				bb = best_b(*stacka, (*stackb)->nbr);
		}
		else if (*stacka && (*stacka)->nbr != bb)
		{
			ra(stacka);
			ft_printf("ra\n");
		}
		if (!is_sorted(*stacka) || !is_sorted(*stackb))
			push_lowest_n(stacka, stackb);
	}
}
