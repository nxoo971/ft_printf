/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/13 22:47:25 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_integer(va_list *param, struct s_spec_info *s)
{
	intptr_t	n;
	int			written;

	written = 0;
	n = va_arg(*param, int);
	s->size_is_specified = vrai;
	s->current_size = len_integer(n, 10);
	s->is_negative = n < 0;
	s->is_null = n == 0;
	if (s->is_negative)
		n = n * -1;
	if (s->space && !s->is_negative)
		written = ft_putchar(' ');
	return (written + not_left_aligned(s, n, 10, faux));
}

/*
int	exec_integer(va_list *param, struct s_spec_info *s)
{
	intptr_t	n;
	int			written;
	int			current_flag;

	written = 0;
	n = va_arg(*param, int);
	s->size_is_specified = vrai;
	s->current_size = len_integer(n, 10) - (int)(s->width_is_specified && s->precision);
	s->is_negative = n < 0;
	s->is_null = (t_bool)n == 0;
	current_flag = -1;
	if (s->space && !s->is_negative)
		current_flag = ' ';
	if (s->plus && !s->is_negative)
		current_flag = '+';
	if (current_flag != -1)
		written += ft_putchar(current_flag);
	if (s->is_negative) {
		n = n * -1;
		if ((s->width_is_specified && s->with_leading_zeroes) || \
			s->precision_is_specified || \
			(!s->width_is_specified && !s->precision_is_specified))
				written += ft_putchar('-');
	}
	if (s->is_left_aligned || s->width_is_specified)
	{
		written += treat_width(s);
		
		if (s->is_negative && written <= 0)
			written += ft_putchar('-');
		if (s->is_null)
			return (written);
		return (written + divide_unsigned_apply_f(n, 10, faux));
	}
	if (s->is_null)
		return (written);
	return (written + divide_unsigned_apply_f(n, 10, faux) + \
			treat_width(s));
}*/
