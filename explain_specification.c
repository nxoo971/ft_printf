/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explain_specification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 02:04:09 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/13 23:07:04 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_test(const struct s_spec_info *s)
{
	int written = 0;
	int width = (s->width - s->current_size);
	//printf("\ntst: %d\n", width);

	if (s->width > 0 && s->precision_is_specified && (s->precision == -1 || s->width > s->precision))
	{
		width = s->width;
		if (s->width > s->precision && s->precision != -1)
			width -= s->precision;
		while (--width >= 0)
			written += ft_putchar(' ');
	}
	if (s->plus)
		width -= 1;
	if (!s->with_leading_zeroes)
	{
		while (--width >= 0)
			written += ft_putchar(' ');
	}
	if (!s->is_left_aligned && ((s->sharp && !s->is_null) || s->current_type == 'p'))
	{
		written += ft_putchar('0');
		if (!s->sharp)
			written += ft_putchar('x');
		else
			written += ft_putchar(s->current_type_sharp);
	}
	if (s->with_leading_zeroes)
	{
		int c = '0';
		if ((s->is_null || (s->precision_is_specified && s->width > s->precision)))
			c = ' ';
		if (s->precision_is_specified && s->precision > 0 && s->precision > s->current_size && s->width > s->precision)
			width -= (s->precision - s->current_size);
		if (s->precision_is_specified && s->precision > s->width && c != ' ')
			width = (s->precision - s->current_size);
		if (s->is_null && s->precision_is_specified && s->precision == 0)
			width += 1;
		while (--width >= 0)
			written += ft_putchar(c);
	}
	// affiche n or s
	return (written);
}

int	explain_specification(const char *start, const char *end, va_list *param)
{
	struct s_spec_info		s;
	static const t_action	actions[256] = {
	['c'] = & exec_char,
	['s'] = & exec_string,
	['p'] = & exec_pointer,
	['d'] = & exec_integer,
	['i'] = & exec_integer,
	['u'] = & exec_unsigned,
	['x'] = & exec_lowerhexa,
	['X'] = & exec_upperhexa,
	['%'] = & exec_percent,
	};

	s = extract_spec_info(start, end);
	if (actions[(unsigned)s.current_type] != NULL)
		return (actions[(unsigned)s.current_type](param, &s));
	return (0);
}
