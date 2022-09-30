/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/30 23:20:22 by nxoo             ###   ########.fr       */
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
	int			i;

	s = va_arg(*params, const char *);
	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}
