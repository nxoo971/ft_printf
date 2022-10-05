/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:05:09 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/05 03:40:22 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_substring(const char *start, const char *end)
{
	const char	*p;
	int			len;

	p = start;
	len = 0;
	while (p < end)
		len += ft_putchar(*p++);
	return (len);
}

static int	is_specifier(char c)
{
	char	*names[256];

	init_names(&names);
	return (names[(unsigned)c] != NULL);
}

static void	main_printf(const char *start, const char *end, \
							int *len, va_list *params)
{
	while (*end != '\0')
	{
		if (e_state == STRING)
		{
			if (*end == '%')
			{
				*len += print_substring(start, end);
				e_state = SPECIFICATION;
				start = end;
			}
		}
		else
		{
			if (is_specifier(*end))
			{
				*len += explain_specification(start, end + 1, params);
				e_state = STRING;
				start = end + 1;
			}
		}
		end++;
	}
	*len += print_substring(start, end);
}

int	ft_printf(const char *format, ...)
{
	va_list		params;
	int			len;
	const char	*p;
	const char	*start;

	p = format;
	start = format;
	e_state = STRING;
	len = 0;
	va_start(params, format);
	main_printf(start, p, &len, &params);
	va_end(params);
	return (len);
}
