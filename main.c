/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:51:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/16 03:37:33 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int a = 0, b = 0;

	float d = 2.33456;

	a = ft_printf("%f", d);
	printf("\n");
	b = printf("%f", d);
	printf("\na: %d - b: %d", a, b);

	printf("\n\n");

	a = ft_printf("%d", 0);
	printf("\n");
	b = printf("%d", 0);
	printf("\na: %d - b: %d", a, b);

	printf("\n\n");

	a = ft_printf("%#-+0i", -1);
	printf("\n");
	b = printf("%#-+0i", -1);
	printf("\na: %d - b: %d", a, b);

	printf("\n\n");

	a = ft_printf("%#-+0i", 0);
	printf("\n");
	b = printf("%#-+0i", 0);
	printf("\na: %d - b: %d", a, b);

	printf("\n\n");

	a = ft_printf("%d|%-d|%+d|% d|%0d", 0, 0, 0, 0, 0);
	printf("\n");
	b = printf("%d|%-d|%+d|% d|%0d", 0, 0, 0, 0, 0);
	printf("\na: %d - b: %d", a, b);

	printf("\n\n");
	return (0);
}
