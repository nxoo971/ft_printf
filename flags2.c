/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:46:32 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/28 17:48:55 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/main.h"

void	flag_x(int n)
{
	divide_n_apply_f(n, &put_x);
}

void	flag_X(int n)
{
	divide_n_apply_f(n, &put_X);
}

void	flag_p(void *ptr)
{
	unsigned long	p;

	p = *((unsigned long *)&ptr);
	divide_n_apply_f(p, &put_x);
}