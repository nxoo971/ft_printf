/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/05 03:36:14 by nxoo             ###   ########.fr       */
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
	if (!s->is_left_aligned)
	{
		if (s->is_negative && \
				(s->with_leading_zeroes || s->precision_is_specified))
			n = n * -1;
		return (written + explain_flag_specification(s) + \
					divide_integer_apply_f(n, 10, &put_integer));
	}
	return (written + divide_integer_apply_f(n, 10, &put_integer) + \
				explain_flag_specification(s));
}
