/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/30 22:03:21 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_pointer(va_list *params)
{
	uintptr_t	n;

	n = (uintptr_t)va_arg(*params, void *);
	return (ft_putstr("0x") + divide_n_apply_f2(n, 16, &put_lowerhexa));
}

int	exec_integer(va_list *params)
{
	intptr_t	n;

	n = va_arg(*params, int);
	return (divide_n_apply_f(n, 10, &put_integer));
}

int	exec_unsigned(va_list *params)
{
	uintptr_t	n;

	n = va_arg(*params, unsigned int);
	return (divide_n_apply_f2(n, 10, &put_unsigned));
}

int	exec_lowerhexa(va_list *params)
{
	uintptr_t	n;

	n = va_arg(*params, unsigned int);
	return (divide_n_apply_f2(n, 16, &put_lowerhexa));
}

int	exec_upperhexa(va_list *params)
{
	uintptr_t	n;

	n = va_arg(*params, unsigned int);
	return (divide_n_apply_f2(n, 16, &put_upperhexa));
}
