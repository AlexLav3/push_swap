/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:56:16 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/21 16:40:00 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s, const char *format)
{
	int	i;

	i = 0;
	(void)format;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
