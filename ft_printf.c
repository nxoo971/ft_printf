/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:54:07 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/30 23:22:47 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_actions(t_action (*actions)[256])
{
	(*actions)['c'] = & exec_char;
	(*actions)['s'] = & exec_string;
	(*actions)['p'] = & exec_pointer;
	(*actions)['i'] = & exec_integer;
	(*actions)['d'] = & exec_integer;
	(*actions)['u'] = & exec_unsigned;
	(*actions)['x'] = & exec_lowerhexa;
	(*actions)['X'] = & exec_upperhexa;
}

int	ft_printf(const char *format, ...)
{
	va_list		params;
	t_action	actions[256];
	t_action	a;
	int			len;

	len = 0;
	init_actions(&actions);
	va_start(params, format);
	while (*format)
	{
		while (*format && *format != '%')
			len += ft_putchar(*format++);
		if (!*format)
			break ;
		if (*++format == '%')
			len += ft_putchar(*format++);
		else
		{
			a = actions[(unsigned)*format++];
			if (a)
				len += a(&params);
		}
	}
	va_end(params);
	return (len);
}
