/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:05:09 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/16 03:02:36 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_substring(const char *start, const char *end)
{
	const char	*p;

	p = start;
	while (p < end)
		ft_putchar(*p++);
	return (p - start);
}

static int	is_type(char c)
{
	static const char *const	names[256] = {
	['c'] = "char",
	['s'] = "char *",
	['p'] = "pointer",
	['d'] = "int",
	['i'] = "int",
	['u'] = "unsigned",
	['x'] = "unsigned hexa",
	['X'] = "unsigned hexa",
	['f'] = "float / double",
	['%'] = "percent",
	};

	return (names[(unsigned)c] != NULL);
}

static t_bool	case_string_specification(const char **start, const char **end, \
											int *len, va_list *params)
{
	if (e_state == STRING)
	{
		if (**end == '%' || **end == '{')
		{
			*len += print_substring(*start, *end);
			if (**end == '%')
				e_state = SPECIFICATION;
			else
				e_state = COLOR;
			*start = *end;
		}
	}
	else if (e_state == SPECIFICATION)
	{
		if (is_type(**end))
		{
			*len += explain_specification(*start, *end + 1, params);
			e_state = STRING;
			*start = *end + 1;
		}
	}
	return (e_state == STRING || e_state == SPECIFICATION);
}

static void	main_printf(const char *start, const char *end, \
							int *len, va_list *params)
{
	char	*tmp;

	while (*end != '\0')
	{
		if (!case_string_specification(&start, &end, len, params))
		{
			if (*end == '}')
			{
				tmp = ft_strnrchr(start, '{', end - start);
				if (tmp != start)
				{
					print_substring(start, tmp);
					start = tmp;
				}
				if (explain_color(start, end + 1))
					e_state = STRING;
				else
					*len += print_substring(start, end + 1);
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
