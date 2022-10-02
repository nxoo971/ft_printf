/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/02 03:20:54 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_char(va_list *params)
{
	return (ft_putchar((uintptr_t)va_arg(*params, int)));
}

int	exec_string(va_list *params)
{
	const char	*s;

	s = va_arg(*params, const char *);
	if (!s)
		s = "(null)";
	return (ft_putstr(s));
}
