/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:51:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/14 20:08:34 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int a = 0, b = 0;

	a = ft_printf("%s %S", "test", "test");
	printf("\n");
	b = printf("%s %S", "test", "");
	printf("\na: %d - b: %d", a, b);
	return (0);
}
