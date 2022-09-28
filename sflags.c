/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:44:07 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/29 00:43:39 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"

void	put_d(int n)
{
	ft_putchar_fd(n + '0', 1);
}

void	put_x(unsigned int n)
{
	ft_putchar_fd(LOWERHEXA[n], 1);
}

void	put_bigx(unsigned int n)
{
	ft_putchar_fd(UPPERHEXA[n], 1);
}

void	put_p(unsigned long int n)
{
	ft_putchar_fd(LOWERHEXA[n], 1);
}

void	put_u(unsigned int n)
{
	ft_putchar_fd(n + '0', 1);
}
