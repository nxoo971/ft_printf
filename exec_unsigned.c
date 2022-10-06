/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/06 22:08:37 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static \
int	_exec_unsigned(struct s_spec_info *s, va_list *param, \
					int base, t_bool lower)
{
	uintptr_t	n;
	int			written;

	n = va_arg(*param, unsigned int);
	s->size_is_specified = vrai;
	s->current_size = len_unsigned(n, base);
	if (s->sharp)
		s->is_negative = n == 0;
	written = pre_explain_flag_specification(s);
	if (!s->is_left_aligned)
		return (written + explain_flag_specification(s) + \
					divide_unsigned_apply_f(n, base, lower));
	return (written + divide_unsigned_apply_f(n, base, lower) + \
				explain_flag_specification(s));
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

	n = (uintptr_t)va_arg(*param, void *);
	s->size_is_specified = vrai;
	s->current_size = len_unsigned(n, 16) + 2;
	if (!s->is_left_aligned)
		return (explain_flag_specification(s) + \
			ft_putstr("0x") + divide_unsigned_apply_f(n, 16, vrai));
	return (ft_putstr("0x") + divide_unsigned_apply_f(n, 16, vrai) + \
				explain_flag_specification(s));
}
