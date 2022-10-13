/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:51:55 by nxoo              #+#    #+#             */
/*   Updated: 2022/10/13 23:25:52 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int a = 0, b = 0;

	printf("%uf", 12);
	printf("\n");
	printf("%0uf", 12);
	printf("\n");
	printf("%05uf", 12);
	printf("\n");
	printf("%1.5uf", 12);
	printf("\n");
	printf("%-020.3uf", 12);
	printf("\n");
	printf("%6.3uf", 12);

	printf("\n");
	printf("\nmine : \n\n");

	ft_printf("%uf", 12);
	ft_printf("\n");
	ft_printf("%0uf", 12);
	ft_printf("\n");
	ft_printf("%05uf", 12);
	ft_printf("\n");
	ft_printf("%1.5uf", 12);
	ft_printf("\n");
	ft_printf("%-020.3uf", 12);
	ft_printf("\n");
	ft_printf("%6.3uf", 12);
	
	ft_printf("\n\n");
	printf("%-15.5X", 2147483647);
	printf("\n");
	ft_printf("%-15.5X", 2147483647);
	
	ft_printf("\n\n");
	printf("%-10.X", 0);
	printf("\n");
	ft_printf("%-10.X", 0);

	ft_printf("\n\n");
	printf("%-10.15X", -1);
	printf("\n");
	ft_printf("%-10.15X", -1);
	
	ft_printf("\n\n");
	printf("% d % d", 2147483647, (int)-2147483648);
	printf("\n");
	ft_printf("% d % d", 2147483647, (int)-2147483648);

	ft_printf("\n\n");
	printf("%.11i", (int)-2147483648);
	printf("\n");
	ft_printf("%.11i", (int)-2147483648);

	ft_printf("\n\n");
	printf("%14i", (int)-2147483648);
	printf("\n");
	ft_printf("%14i", (int)-2147483648);

	ft_printf("\n\n");
	printf("%02.0ia", 0);
	printf("\n");
	ft_printf("%02.0ia", 0);

	ft_printf("\n\n");
	printf("%-1.0i", -10);
	printf("\n");
	ft_printf("%-1.0i", -10);

	ft_printf("\n\n");
	printf("%-10.2i", -10);
	printf("\n");
	ft_printf("%-10.2i", -10);

	ft_printf("\n\n");
	printf("%-10.5i", 2147483647);
	printf("\n");
	ft_printf("%-10.5i", 2147483647);

	ft_printf("\n\n");
	printf("%.0x", 0);
	printf("\n");
	ft_printf("%.0x", 0);

	ft_printf("\n\n");
	printf("%020.10i", -42000);
	printf("\n");
	ft_printf("%020.10i", -42000);

	ft_printf("\n\n");
	printf("%-10x", 1);
	printf("\n");
	ft_printf("%-10x", 1);

	ft_printf("\n\n");
	printf("%-10i", -1);
	printf("\n");
	ft_printf("%-10i", -1);

	ft_printf("\n\n");
	printf("%01.0ia", 0);
	printf("\n");
	ft_printf("%01.0ia", 0);
	
	ft_printf("\n\n");
	printf("%1.sa", "21-school.ru");
	printf("\n");
	ft_printf("%1.sa", "21-school.ru");
	
	printf("\n\n");
	printf("%-4.1s", "for");
	printf("\n");
	ft_printf("%-4.1s", "for");
	
	printf("\n\n");
	printf("%--4.1s %s %------------------9.3s of %s of %-5.7sa", "for", "the", "goooood", "aaall", "ugsss");
	printf("\n");
	ft_printf("%--4.1s %s %------------------9.3s of %s of %-5.7sa", "for", "the", "goooood", "aaall", "ugsss");

//	printf("\na: %d - b: %d", a, b);
	return (0);
}
