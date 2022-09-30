/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:55:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/30 23:22:10 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define UPPERHEXA	"0123456789ABCDEF"
# define LOWERHEXA	"0123456789abcdef"

typedef int	(*t_action)(va_list *);
// ft_printf.c
int		ft_printf(const char *format, ...);
// exec_n.c
int		exec_pointer(va_list *params);
int		exec_integer(va_list *params);
int		exec_unsigned(va_list *params);
int		exec_lowerhexa(va_list *params);
int		exec_upperhexa(va_list *params);
// exec_str.c
int		exec_char(va_list *params);
int		exec_string(va_list *params);
// puts_essentials.c
int		ft_putchar(int c);
int		ft_putstr(const char *s);
// puts.c
void	put_integer(intptr_t c);
void	put_unsigned(uintptr_t c);
void	put_lowerhexa(uintptr_t c);
void	put_upperhexa(uintptr_t c);
// operations.c
int		divide_n_apply_f(intptr_t n, int base, void (f)(intptr_t));
int		divide_n_apply_f2(uintptr_t n, int base, void (f)(uintptr_t));

#endif
