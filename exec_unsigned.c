/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/13 22:52:05 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ABS(x)	((x < 0) ? x * -1 : x)

static \
int	print_prefix(struct s_spec_info *s)
{
	int	written;

	written = 0;
	if (s->sharp && !s->is_null)
	{
		written += ft_putchar('0');
		written += ft_putchar(s->current_type_sharp);
	}
	return (written);
}

static \
int	print_w(int width, int c)
{
	int	written = 0;
	while (--width >= 0)
		written += ft_putchar(c);
	return (written);
}

static \
int	precision_is_not_specified(struct s_spec_info *s, uintptr_t n, int base, t_bool lower)
{
	int	c = 0, width = 0, written = 0;
	if (!s->precision_is_specified)
	{
		if (s->width_is_specified && s->width > 0)
		{
			c = '0';
			if (s->current_size > s->width)
				width = 0;
			else
				width = s->width - s->current_size;
			//if (s->is_negative)
				//width += 1;
			if (!s->with_leading_zeroes)
			{
				c = ' ';
				if (s->is_left_aligned)
				{
					/* %d - %i */
					if (s->is_negative)
						written += ft_putchar('-');
					if (s->plus && !s->is_negative)
						written += ft_putchar('+');
					/* ******* */
				}
			}
			if (c == '0')
			{
				/* %d - %i */
				if (s->is_negative)
					written += ft_putchar('-');
				if (s->plus && !s->is_negative)
					written += ft_putchar('+');
				/* ******* */
				written += print_prefix(s);
			}
			if (s->is_left_aligned)
				written += divide_unsigned_apply_f(n, base, lower);
			written += print_w(width, c);
			if (c == ' ')
			{
				if (!s->is_left_aligned)
				{
					/* %d - %i */
					if (s->is_negative)
						written += ft_putchar('-');
					if (s->plus && !s->is_negative)
						written += ft_putchar('+');
					/* ******* */
				}
				written += print_prefix(s);
			}
			if (!s->is_left_aligned)
				return (written + divide_unsigned_apply_f(n, base, lower));
			return (written);
		}
		/* %d - %i */
		if (s->is_negative)
			written += ft_putchar('-');
		if (s->plus && !s->is_negative)
			written += ft_putchar('+');
		/* ******* */
		return (written + print_prefix(s) + divide_unsigned_apply_f(n, base, lower));
	}
	return (written);
}

int	not_left_aligned(struct s_spec_info *s, uintptr_t n, int base, t_bool lower)
{
	int written = 0, width = 0;

	written += precision_is_not_specified(s, n, base, lower);
	if (s->precision_is_specified)
	{
		if (s->precision > 0 && s->precision > s->current_size - (int)s->is_negative)
		{
			int prec = s->precision - s->current_size + (int)s->is_negative;
		//	printf("\n%d [%d-%d]\n", prec, s->precision, s->current_size);

			if (s->width_is_specified && s->width > 0 && s->width >= s->precision)
			{
				width = s->width - s->precision - (int)s->is_negative;
				if (!s->is_left_aligned)
					written += print_w(width, ' ');

			/* %d - %i */
				if (s->is_negative)
					written += ft_putchar('-');
				if (s->plus && !s->is_negative)
					written += ft_putchar('+');
			/* ******* */

				written += print_prefix(s);
				if (s->is_left_aligned && !prec)
					written += divide_unsigned_apply_f(n, base, lower);

				written += print_w(prec, '0');
				if (s->is_left_aligned && prec)
					written += divide_unsigned_apply_f(n, base, lower);
				if (s->is_left_aligned)
					written += print_w(width, ' ');
			}
			else
			{
				written += print_prefix(s);
			/* %d - %i */
				if (s->is_negative)
					written += ft_putchar('-');
				if (s->plus && !s->is_negative)
					written += ft_putchar('+');
			/* ******* */
				if (s->is_left_aligned)
				{
					written += print_w(prec, '0');
					written += divide_unsigned_apply_f(n, base, lower);
				}
				else
					written += print_w(prec, '0');
			}
			if (!s->is_left_aligned)
				return (written + divide_unsigned_apply_f(n, base, lower));
			return (written);
		}
		else
		{
			if (s->width_is_specified && s->width > 0 && s->width > s->current_size - (int)s->is_null)
			{
				width = (s->width - s->current_size) + (int)s->is_null;
				if ((s->precision_is_specified && s->precision > 0 && n == 0) || (s->precision <= 0))
					width -= 1;
				if ((s->precision <= 0 && n == 0)/* || (s->precision <= 0 && n == 0 && s->width > 0)*/)
					width = s->width;
				if (!s->is_left_aligned)
					written += print_w(width, ' ');
			/* %d - %i */
				if (s->is_negative)
					written += ft_putchar('-');
				if (s->plus && !s->is_negative)
					written += ft_putchar('+');
			/* ******* */
				written += print_prefix(s);
				if (s->is_left_aligned)
				{
					if (s->precision_is_specified && s->precision > 0)
						written += divide_unsigned_apply_f(n, base, lower);
				}
				if (s->is_left_aligned)
					written += print_w(width, ' ');
			}
			else
			{
			/* %d - %i */
				if (s->is_negative)
					written += ft_putchar('-');
				if (s->plus && !s->is_negative)
					written += ft_putchar('+');
			/* ******* */
				if (s->precision <= 0 && n == 0)
					return (written);
				return (written + divide_unsigned_apply_f(n, base, lower));
			}
		}
		if (s->precision <= 0 && n == 0)
			return (written);

		written += print_prefix(s);
		if (!s->is_left_aligned)
			written += divide_unsigned_apply_f(n, base, lower);
	}
	return (written);
}

static \
int	_exec_unsigned(struct s_spec_info *s, va_list *param, \
					int base, t_bool lower)
{
	uintptr_t	n;
	int			written;

	written = 0;
	n = va_arg(*param, unsigned int);
	s->size_is_specified = vrai;				/* specifier # conversion */
	s->current_size = len_unsigned(n, base) ;
	s->is_null = n == 0;

	//if (!s->is_left_aligned)
		return (not_left_aligned(s, n, base, lower));
	//return (written);
}

int	exec_unsigned(va_list *param, struct s_spec_info *s)
{
	return (_exec_unsigned(s, param, 10, faux));
}

int	exec_lowerhexa(va_list *param, struct s_spec_info *s)
{
	return (_exec_unsigned(s, param, 16, vrai));
}

int	exec_upperhexa(va_list *param, struct s_spec_info *s)
{

	return (_exec_unsigned(s, param, 16, faux));
}

int	exec_pointer(va_list *param, struct s_spec_info *s)
{
	uintptr_t	n;
	int			written;

	n = (uintptr_t)va_arg(*param, void *);
	s->size_is_specified = vrai;
	s->current_size = len_unsigned(n, 16) + 2;
	written = 0;
	if (s->precision > 0) {
		if (s->with_leading_zeroes)
			s->current_size -= 2;
	}
	if (s->is_left_aligned && s->precision <= 0)
		return (ft_putstr("0x") + divide_unsigned_apply_f(n, 16, vrai) + treat_test(s));
	if (s->precision_is_specified)
		written = ft_putstr("0x");
	written += treat_test(s);
	return (written + divide_unsigned_apply_f(n, 16, vrai));
}
