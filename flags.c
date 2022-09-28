/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:03:21 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/28 17:48:18 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/main.h"

void	flag_c(int c)
{
	ft_putchar_fd(c, 1);
}

void	flag_s(char *s)
{
	ft_putstr_fd(s, 1);
}

void	flag_d(int n)
{
	ft_putnbr_fd(n, 1);
}
