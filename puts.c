/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:26:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/30 21:08:32 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_integer(intptr_t c)
{
	ft_putchar(c + '0');
}

void	put_unsigned(uintptr_t c)
{
	ft_putchar(c + '0');
}

void	put_lowerhexa(uintptr_t c)
{
	ft_putchar(LOWERHEXA[c]);
}

void	put_upperhexa(uintptr_t c)
{
	ft_putchar(UPPERHEXA[c]);
}
