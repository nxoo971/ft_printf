/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 02:23:47 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/05 03:36:04 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_spec_info(struct s_spec_info *s)
{
	s->is_left_aligned = faux;
	s->with_leading_zeroes = faux;
	s->space = faux;
	s->plus = faux;
	s->sharp = faux;
	s->current_type_sharp = -1;
	s->width_is_specified = faux;
	s->width = 0;
	s->precision_is_specified = faux;
	s->precision = 0;
	s->half_count = 0;
	s->long_count = 0;
	s->is_size_t = faux;
	s->current_type = -1;
	s->is_negative = faux;
	s->is_empty = faux;
	s->size_is_specified = faux;
	s->current_size = 0;
}

void	init_actions(t_action (*actions)[256])
{
	int	i;

	i = -1;
	while (++i < 256)
		(*actions)[i] = 0;
	(*actions)['c'] = & exec_char;
	(*actions)['s'] = & exec_string;
	(*actions)['p'] = & exec_pointer;
	(*actions)['d'] = & exec_integer;
	(*actions)['i'] = & exec_integer;
	(*actions)['u'] = & exec_unsigned;
	(*actions)['x'] = & exec_lowerhexa;
	(*actions)['X'] = & exec_upperhexa;
}

void	init_names(char *(*names)[256])
{
	int	i;

	i = -1;
	while (++i < 256)
		(*names)[i] = 0;
	(*names)['c'] = "char";
	(*names)['s'] = "char *";
	(*names)['p'] = "pointer";
	(*names)['d'] = "int";
	(*names)['i'] = "int";
	(*names)['u'] = "unsigned";
	(*names)['x'] = "unsigned hexa";
	(*names)['X'] = "unsigned hexa";
	(*names)['%'] = "percent";
}
