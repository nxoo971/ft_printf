/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:21:00 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/06 23:09:00 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define SIZE	2 /* upper and lower base */

int	divide_unsigned_apply_f(uintptr_t n, int base, t_bool lower)
{
	static int					len;
	static const char *const	bases[SIZE] = {BASE, LOWERBASE};

	len = 0;
	if (n >= (unsigned)base)
		divide_unsigned_apply_f(n / base, base, lower);
	len += ft_putchar(bases[lower][n % base]);
	return (len);
}
