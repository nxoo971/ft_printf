/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explain_specification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 02:04:09 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/06 22:23:49 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pre_explain_flag_specification(const struct s_spec_info *s)
{
	int		written;
	char	current_flag;

	written = 0;
	current_flag = -1;
	if (s->size_is_specified)
	{
		if (s->current_type == 'd' || s->current_type == 'i')
		{
			if (s->space && !s->is_negative)
				current_flag = ' ';
			if (s->plus && !s->is_negative)
				current_flag = '+';
			if (current_flag != -1)
				written = ft_putchar(current_flag);
		}
		if ((s->current_type == 'x' || s->current_type == 'X') && \
				s->sharp && !s->is_negative)
		{
			written = ft_putchar('0');
			written += ft_putchar(s->current_type_sharp);
		}
	}
	return (written);
}

static \
int	explain_flag_specification2(const struct s_spec_info *s, int written)
{
	int	len;

	if (s->current_type != 's' && s->precision_is_specified)
	{
		if (s->is_negative)
			len = s->precision - (s->current_size - 1);
		else
			len = s->precision - s->current_size;
		while (len > 0)
		{
			written += ft_putchar('0');
			len--;
		}
	}
	return (written);
}

int	explain_flag_specification(const struct s_spec_info *s)
{
	char	c;
	int		written;
	int		len;

	c = ' ';
	written = 0;
	if (s->width_is_specified)
	{
		if (s->with_leading_zeroes)
			c = '0';
		if (s->width && s->size_is_specified)
		{
			len = s->width - s->current_size;
			if (s->precision_is_specified)
				len = s->width - (s->current_size + s->precision - \
						(s->is_negative == vrai));
			while (len-- > 0)
				written += ft_putchar(c);
		}
	}
	return (explain_flag_specification2(s, written));
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
