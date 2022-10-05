/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/05 03:36:40 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_char(va_list *param, struct s_spec_info *s)
{
	s->size_is_specified = vrai;
	s->current_size = 1;
	if (s->is_left_aligned)
		return (ft_putchar((uintptr_t)va_arg(*param, int)) + explain_flag_specification(s));
	return (explain_flag_specification(s) + ft_putchar((uintptr_t)va_arg(*param, int)));
}

int	exec_string(va_list *param, struct s_spec_info *s)
{
	const char	*str;
	int			i;

	str = va_arg(*param, const char *);
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		i++;
	s->size_is_specified = vrai;
	s->current_size = i;
	s->is_empty = i == 0;
	if (s->space && !s->is_left_aligned && i == 1 && !*str)
		ft_putchar(' ');
	if (!s->precision_is_specified)
	{
		if (s->is_left_aligned)
			return (write(1, str, i) + explain_flag_specification(s));
		return (explain_flag_specification(s) + write(1, str, i));
	}
	if (s->precision_is_specified && s->precision > 0)
	{
		if (s->is_left_aligned)
			return (write(1, str, i) + explain_flag_specification(s));
		return (explain_flag_specification(s) + write(1, str, i));
	}
	return (0);
}
