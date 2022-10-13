/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:06:24 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/13 18:21:16 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	accept_flag_char(struct s_spec_info *s, char c)
{
	if (c == '#')
		s->sharp = vrai;
	else if (c == '-')
	{
		s->is_left_aligned = vrai;
		s->pad = PAD_RIGHT;
	}
	else if (c == '+')
		s->plus = vrai;
	else if (c == ' ' && !s->plus) {
		if (!s->plus) {
			s->space = vrai;
			s->plus = faux;
		}
	}
	else if (c == '0')
		s->with_leading_zeroes = vrai;
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
		if (s->precision == -1)
			s->precision = 0;
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
