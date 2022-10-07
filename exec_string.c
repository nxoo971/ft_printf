/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/06 23:11:21 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_char(va_list *param, struct s_spec_info *s)
{
	s->size_is_specified = vrai;
	s->current_size = 1;
	if (s->is_left_aligned)
		return (ft_putchar((uintptr_t)va_arg(*param, int)) + \
				explain_flag_specification(s));
	return (explain_flag_specification(s) + \
				ft_putchar((uintptr_t)va_arg(*param, int)));
}

int	exec_percent(va_list *param, struct s_spec_info *s)
{
	(void)param;
	(void)s;
	return (ft_putchar('%'));
}

int	exec_string(va_list *param, struct s_spec_info *s)
{
	const char	*str;
	int			i;
	int			written;

	str = va_arg(*param, const char *);
	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	s->size_is_specified = vrai;
	s->current_size = i;
	if ((s->space && !s->is_left_aligned && i > 0 && !*str))
		ft_putchar(' ');
	if (s->is_left_aligned)
		return (write(1, str, i) + explain_flag_specification(s));
	if (!s->precision_is_specified)
		return (explain_flag_specification(s) + write(1, str, i));
	if (s->precision < i - 1 && s->precision != 0)
		return (ft_putchar(' '));
	written = explain_flag_specification(s);
	if (written > 0)
		return (written + write(1, str, i));
	return (ft_putnstr(str, s->precision));
}
