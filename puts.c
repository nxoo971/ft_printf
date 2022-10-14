/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:26:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/14 23:14:47 by nxoo             ###   ########.fr       */
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

int	ft_putnstr(const char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
		i++;
	return (write(1, s, i));
}

void	put_integer(const int c, const char *sbase, const int base)
{
	ft_putchar(sbase[c % base]);
}
