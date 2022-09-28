/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:41:50 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/28 23:26:50 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"

void	divide_n_apply_f(int n, int base, void (*f)(int), int *len)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		nb = n * -1;
		*len += 1;
	}
	if (nb >= (unsigned int)base)
		divide_n_apply_f(nb / base, base, f, len);
	*len += 1;
	f(nb % base);
}

void	divide_n_apply_f2(unsigned long n, int base, void (*f)(int), int *len)
{
	if (n >= (unsigned long)base)
		divide_n_apply_f(n / base, base, f, len);
	*len += 1;
	f(n % base);
}
