/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:21:00 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/30 23:20:48 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	d1(intptr_t n, int base, void (f)(intptr_t), int *calclen)
{
	if (n < 0)
	{
		n = n * -1;
		*calclen += 1;
		ft_putchar('-');
	}
	if (n >= base)
		d1(n / base, base, f, calclen);
	f(n % base);
	return (*calclen += 1);
}

int	divide_n_apply_f(intptr_t n, int base, void (f)(intptr_t))
{
	int	len;

	len = 0;
	d1(n, base, f, &len);
	return (len);
}

static int	d2(uintptr_t n, int base, void (f)(uintptr_t), int *calclen)
{
	if (n >= (uintptr_t)base)
		d2(n / base, base, f, calclen);
	f(n % base);
	return (*calclen += 1);
}

int	divide_n_apply_f2(uintptr_t n, int base, void (f)(uintptr_t))
{
	int	len;

	len = 0;
	d2(n, base, f, &len);
	return (len);
}
