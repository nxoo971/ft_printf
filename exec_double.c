/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:40:19 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/16 04:01:44 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DEFAULT_SIZE	6
/*
static \
int	print_zero(int width)
{
	int	written;

	written = 0;
	while (--width >= 0)
		written += ft_putchar('0');
	return (written);
}*/

int	exec_double(va_list *param, struct s_spec_info *s)
{
	(void)s;
	double	n;
	int		written = 0;

	n = va_arg(*param, double);
	written += ft_printf("%d.", (int)n);
    n -= (int)n;
    int count = 6;
    while(n - (int)n < 1 && count > 0) {
        n *= 10;
      written += ft_putchar((int)n+'0');
       n -= (int)n;
        count--;
   }
   return (written);
}
