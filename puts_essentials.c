/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_essentials.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 21:08:11 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/30 23:22:36 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}
