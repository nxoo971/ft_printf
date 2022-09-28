/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:41:50 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/28 17:47:48 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/main.h"

void	divide_n_apply_f(long long n, void (*f)(void *))
{
	if (n >= 16)
		divide_n_apply_f(n / 16, f);
	f((void *)n);
}
