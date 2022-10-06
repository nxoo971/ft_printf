/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_spec_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:06:24 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/06 22:29:50 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static struct s_spec_info	init_spec(void)
{
	static const struct s_spec_info	s = {
		.is_left_aligned = faux,
		.with_leading_zeroes = faux,
		.space = faux,
		.plus = faux,
		.sharp = faux,
		.current_type_sharp = -1,
		.width_is_specified = faux,
		.width = 0,
		.precision_is_specified = faux,
		.precision = 0,
		.half_count = 0,
		.long_count = 0,
		.is_size_t = faux,
		.current_type = -1,
		.is_negative = faux,
		.is_empty = faux,
		.size_is_specified = faux,
		.current_size = 0,
	};

	return (s);
}

struct s_spec_info	extract_spec_info(const char *start, const char *end)
{
	struct s_spec_info			s;
	const char					*p;

	p = start + 1;
	s = init_spec();
	while (accept_flag_char(&s, *p))
		p++;
	while (accept_width_char(&s, *p))
		p++;
	if (*p == '.')
	{
		p++;
		s.precision_is_specified = vrai;
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