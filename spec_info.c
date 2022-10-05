/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:06:24 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/05 03:48:40 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	accept_flag_char(struct s_spec_info *s, char c)
{
	if (c == '-')
		s->is_left_aligned = vrai;
	else if (c == '0')
		s->with_leading_zeroes = vrai;
	else if (c == ' ')
		s->space = vrai;
	else if (c == '+')
		s->plus = vrai;
	else if (c == '#')
		s->sharp = vrai;
	else
		return (faux);
	return (vrai);
}

t_bool	accept_width_char(struct s_spec_info *s, char c)
{
	if (ft_isdigit(c))
	{
		s->width_is_specified = vrai;
		s->width = 10 * s->width + c - '0';
		return (vrai);
	}
	return (faux);
}

t_bool	accept_precision_char(struct s_spec_info *s, char c)
{
	if (ft_isdigit(c))
	{
		s->precision_is_specified = vrai;
		s->precision = 10 * s->precision + c - '0';
		return (vrai);
	}
	return (faux);
}

t_bool	accept_type_char(struct s_spec_info *s, char c)
{
	if (c == 'h')
		s->half_count++;
	else if (c == 'l')
		s->long_count++;
	else if (c == 'z')
		s->is_size_t++;
	else
		return (faux);
	return (vrai);
}

struct s_spec_info	extract_spec_info(const char *start, const char *end)
{
	struct s_spec_info			s;
	const char					*p;

	p = start + 1;
	init_spec_info(&s);
	while (accept_flag_char(&s, *p))
		p++;
	while (accept_width_char(&s, *p))
		p++;
	if (*p == '.')
	{
		p++;
		while (accept_precision_char(&s, *p))
			p++;
	}
	while (accept_type_char(&s, *p))
		p++;
	if (s.sharp)
		s.current_type_sharp = end[-1];
	s.current_type = end[-1];
	return (s);
}
