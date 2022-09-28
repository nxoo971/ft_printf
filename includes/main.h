/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:56:59 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/28 18:07:51 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdarg.h>
# include <stdio.h>

# define SIZEFUNC	6
# define UPPERHEXA	"0123456789ABCDEF"
# define LOWERHEXA	"0123456789abcdef"

typedef struct	s_func
{
	void	(*func)(void *);
	char	c;
}				t_func;

// xflags
void	divide_n_apply_f(long long n, void (*f)(void *));
// flags
void	flag_c(int c);
void	flag_s(char *s);
void	flag_d(int n);
// sflags
void	put_x(void *n);
void	put_X(void *n);
// flags2
void	flag_x(int n);
void	flag_X(int n);
void	flag_p(void *ptr);

#endif