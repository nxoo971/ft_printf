/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:28:10 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/13 21:12:28 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_unsigned(uintptr_t nb, int base)
{
	int	count;

	count = 0;
	while (nb >= (unsigned)base)
	{
		count++;
		nb /= base;
	}
	return (count + 1);
}

int	len_integer(intptr_t nb, int base)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count = 1;
		nb = nb * -1;
	}
	while (nb >= base)
	{
		count++;
		nb /= base;
	}
	return (count + 1);
}
