/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/14 02:35:06 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static \
int	_exec_unsigned(struct s_spec_info *s, va_list *param, \
					int base, t_bool lower)
{
	uintptr_t	n;
	int			written;

	written = 0;
	n = va_arg(*param, unsigned int);
	s->size_is_specified = vrai;
	s->current_size = len_unsigned(n, base);
	s->is_null = n == 0;

	return (print_algo_flag(s, n, base, lower));
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
	return (print_algo_flag(s, n, 16, vrai));
}
