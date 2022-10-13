/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:01 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/13 23:17:02 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	exec_char(va_list *param, struct s_spec_info *s)
{
	s->size_is_specified = vrai;
	s->current_size = 1;
	if (s->is_left_aligned)
		return (ft_putchar((uintptr_t)va_arg(*param, int)) + treat_test(s));
	return (treat_test(s) + ft_putchar((uintptr_t)va_arg(*param, int)));
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
	int			written = 0;

	str = va_arg(*param, const char *);
	if (!str)
		str = "(null)";
	i = ft_strlen(str);
	s->size_is_specified = vrai;
	s->current_size = i;
	if ((s->space && !s->is_left_aligned && i > 0 && !*str))
		ft_putchar(' ');
	if (s->is_left_aligned)
	{
		if (s->precision_is_specified) {
			if (s->precision == -1)
				return (treat_test(s));
			return (written + write(1, str, s->precision) + treat_test(s));
		}
		return (write(1, str, i) + treat_test(s));
	}
	if (s->precision_is_specified) {
		written += treat_test(s);
		if (s->precision == -1)
			return (written);
		return (written + ft_putnstr(str, s->precision));
	}
	return (treat_test(s) + ft_putnstr(str, i));
}
