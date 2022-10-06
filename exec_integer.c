/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/06 21:46:42 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_integer(va_list *param, struct s_spec_info *s)
{
	intptr_t	n;
	int			written;

	n = va_arg(*param, int);
	s->size_is_specified = vrai;
	s->current_size = len_integer(n, 10);
	s->is_negative = n < 0;
	written = pre_explain_flag_specification(s);
	if (s->is_negative)
	{
		written += ft_putchar('-');
		n = n * -1;
	}
	if (!s->is_left_aligned)
		return (written + explain_flag_specification(s) + \
					divide_unsigned_apply_f(n, 10, faux));
	return (written + divide_unsigned_apply_f(n, 10, faux) + \
				explain_flag_specification(s));
}
