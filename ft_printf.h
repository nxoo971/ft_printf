/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 01:05:34 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/14 22:22:25 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define BASE		"0123456789ABCDEF"
# define LOWERBASE	"0123456789abcdef"

enum
{
	STRING,
	SPECIFICATION,
	COLOR
}
e_state;

enum e_bool
{
	faux,
	vrai
};
typedef enum e_bool	t_bool;

struct s_spec_info {
	t_bool	is_left_aligned;
	t_bool	with_leading_zeroes;
	t_bool	plus;
	t_bool	space;
	t_bool	sharp;

	t_bool	width_is_specified;
	int		width;

	t_bool	precision_is_specified;
	int		precision;

	int		half_count;
	int		long_count;
	t_bool	is_size_t;

	char	current_type;
	int		current_size;
	t_bool	is_negative;
	t_bool	is_null;
};

typedef int			(*t_action)(va_list *, struct s_spec_info *s);

int					ft_printf(const char *format, ...);
int					explain_specification(const char *start, const char *end, \
											va_list *param);
// s_spec_info.c
struct s_spec_info	extract_spec_info(const char *start, const char *end);
// accept.c
t_bool				accept_flag_char(struct s_spec_info *s, char c);
t_bool				accept_width_char(struct s_spec_info *s, char c);
t_bool				accept_precision_char(struct s_spec_info *s, char c);
t_bool				accept_type_char(struct s_spec_info *s, char c);
// algo_flag.c
int					print_algo_flag(struct s_spec_info *s, uintptr_t n, int base, t_bool lower);
// print.c
int					print_prefix(const struct s_spec_info *s);
int					print_sign(const struct s_spec_info *s);
int					print_width(int width, int c);
// exec_integer.c
int					exec_integer(va_list *param, struct s_spec_info *s);
// exec_unsigned.c
int					exec_pointer(va_list *param, struct s_spec_info *s);
int					exec_unsigned(va_list *param, struct s_spec_info *s);
int					exec_lowerhexa(va_list *param, struct s_spec_info *s);
int					exec_upperhexa(va_list *param, struct s_spec_info *s);
// exec_string.c
int					exec_char(va_list *param, struct s_spec_info *s);
int					exec_percent(va_list *param, struct s_spec_info *s);
int					exec_string(va_list *param, struct s_spec_info *s);
// operations.c
int					divide_unsigned_apply_f(uintptr_t n, int base, \
												t_bool lower);
// puts.c
int					ft_putchar(int c);
int					ft_putstr(const char *s);
int					ft_putnstr(const char *s, int len);
void				put_integer(int c, const char *sbase, const int base);

// calc_len.c
int					len_unsigned(uintptr_t nb, int base);
int					len_integer(intptr_t nb, int base);
// color.c
t_bool				explain_color(const char *start, const char *end);

#endif
