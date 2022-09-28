/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:50:36 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/29 00:28:20 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# define SIZEFUNC	10
# define UPPERHEXA	"0123456789ABCDEF"
# define LOWERHEXA	"0123456789abcdef"
# define HEXABASE	16
# define DECBASE	10

typedef struct s_func
{
	void	(*func)(void *, int *);
	char	c;
}				t_func;

int		ft_printf(const char *format, ...);
// flags
void	flag_c(int c, int *len);
void	flag_s(char *s, int *len);
void	flag_d(int n, int *len);
void	flag_i(int n, int *len);
// flags2
void	flag_x(unsigned int n, int *len);
void	flag_bigx(unsigned int n, int *len);
void	flag_u(unsigned int n, int *len);
void	flag_p(unsigned long cptr, int *len);
// xflags
void	divide_n_apply_f(int n, int base, void (*f)(int), int *len);
void	divide_n_apply_f2(unsigned long n, int base, void (*f)(int), int *len);
// sflags
void	put_d(int n);
void	put_x(unsigned int n);
void	put_bigx(unsigned int n);
void	put_p(unsigned long n);
void	put_u(unsigned int n);

#endif