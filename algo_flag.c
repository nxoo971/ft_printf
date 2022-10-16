/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:33:37 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/16 04:01:09 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static \
int	precision_is_not_specified(const struct s_spec_info *s, \
									uintptr_t n, int base, t_bool lower)
{
	int	c;
	int	width;

	c = '0';
	width = 0;
	if (s->width_is_specified && s->width > 0)
	{
		if (s->current_size <= s->width)
		{
			width = (s->width - s->current_size);
			width -= (s->space && !s->plus);
			if (s->space && s->is_negative && !s->is_null)
				width += 1;
			if (s->current_type == 'd' || s->current_type == 'i')
				width -= (s->plus && !s->space && !s->is_negative);
		}
		if (!s->with_leading_zeroes || (s->with_leading_zeroes && s->is_left_aligned))
			c = ' ';
	}
	if (!s->with_leading_zeroes && s->is_left_aligned)
		return (print_sign(s) + print_prefix(s) + divide_unsigned_apply_f(n, base, lower) + print_width(width, c));
	if (!s->with_leading_zeroes)
	{
		//printf("tst454 - %d\n\n", s->width);
		return (print_width(width, c) + print_prefix(s) + print_sign(s) + divide_unsigned_apply_f(n, base, lower));
	}
	if (s->is_left_aligned)
		return (print_sign(s) + print_prefix(s) + divide_unsigned_apply_f(n, base, lower) + print_width(width, c));
	return (print_sign(s) + print_prefix(s) + print_width(width, c) + divide_unsigned_apply_f(n, base, lower));
}

static \
int	precision_is_specified_and_greater_than_currentsize(\
	const struct s_spec_info *s, uintptr_t n, int base, t_bool lower)
{
	int	width;
	int	prec;
	int	written;

	width = 0;
	written = 0;
	prec = (s->precision - s->current_size) + (int)s->is_negative;
	if (s->width_is_specified && s->width >= s->precision)
		width = (s->width - s->precision) - s->is_negative - (s->space && !s->is_negative) - (s->plus && !s->is_negative);


	if (!s->is_left_aligned)
		written += print_width(width, ' ');

	written += print_sign(s) + print_prefix(s);
	if (s->is_left_aligned && !prec)
		return (written + divide_unsigned_apply_f(n, base, lower) + print_width(width, ' '));

	written += print_width(prec, '0');
	if (s->is_left_aligned && prec)
		return (written + divide_unsigned_apply_f(n, base, lower) + print_width(width, ' '));

	return (written + divide_unsigned_apply_f(n, base, lower));
}

static \
int	width_is_specified_and_greater_than_currentsize(const struct s_spec_info *s, uintptr_t n, int base, t_bool lower)
{
	int	width;
	int	prec;
	int	written;

	width = 0;
	prec = 0;
	written = 0;
	if (s->width_is_specified && s->width > s->current_size - (int)s->is_null)
	{
		width = (s->width - s->current_size);
		
		if (s->precision <= 0 && s->is_null)
			width = s->width;

		width -= (s->space && !s->plus);
		if (s->space && s->is_negative)
			width += 1;

		if (s->current_type == 'd' || s->current_type == 'i')
			width -= (s->plus && !s->space && !s->is_negative);
		if (!s->is_left_aligned)
			written += print_width(width, ' ') + print_sign(s) + print_prefix(s);
		else
			written += print_sign(s) + print_prefix(s);

		if (s->is_left_aligned)
		{
			if (!s->is_null)
				written += divide_unsigned_apply_f(n, base, lower);
			return (written + print_width(width, ' '));
		}
	}
	else
		written += print_sign(s) + print_prefix(s);
	if (s->precision <= 0 && s->is_null)
		return (written);
	return (written + divide_unsigned_apply_f(n, base, lower));
}

int	print_algo_flag(const struct s_spec_info *s, uintptr_t n, int base, t_bool lower)
{
	if (!s->precision_is_specified)
		return (precision_is_not_specified(s, n, base, lower));
	if (s->precision_is_specified)
	{
		if (s->precision > s->current_size - (int)s->is_negative)
			return (precision_is_specified_and_greater_than_currentsize(s, n, base, lower));
	}
	return (width_is_specified_and_greater_than_currentsize(s, n, base, lower));
}
