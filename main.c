/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:29:09 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/28 16:38:04 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/main.h"

void    init_tfunc(t_func (*ptr)[SIZEFUNC])
{
    (*ptr)[0].func = (void *)&flag_c;
    (*ptr)[0].c = 'c';
    (*ptr)[1].func = (void *)&flag_s;
    (*ptr)[1].c = 's';
    (*ptr)[2].func = (void *)&flag_d;
    (*ptr)[2].c = 'd';
    (*ptr)[3].func = (void *)&flag_x;
    (*ptr)[3].c = 'x';
    (*ptr)[4].func = (void *)&flag_X;
    (*ptr)[4].c = 'X';
    (*ptr)[5].func = (void *)&flag_p;
    (*ptr)[5].c = 'p';
}


int	index_of_key(t_func ptr[SIZEFUNC], char c)
{
	int	i;

	i = 0;
	while (ptr[i].c != -1)
	{
		if (ptr[i].c == c)
			return (i);
		i++;
	}
	return (-1);
}

int ft_printf(const char *format, ...)
{
	t_func	ptr[SIZEFUNC];
	va_list	args_infos;
	int		indexof;
	int		i;

	i = 0;
	init_tfunc(&ptr);
	va_start(args_infos, format);
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			ft_putchar_fd(format[i++], 1);
		if (!format[i])
			break ;
		indexof = index_of_key(ptr, format[++i]);
		if (indexof >= 0)
			ptr[indexof].func(va_arg(args_infos, void *));
		i++;
	}
	va_end(args_infos);
	return (0);
}

int main(void)
{
	int a = 8;
	ft_printf("test%cddd%cdddd%s%d%x-%p", 'a', 'b', "cde",2147483647, 8576, &a);
    ft_printf("\n");
	printf("test%cddd%cdddd%s%d%x-%p", 'a', 'b', "cde",2147483647, 8576, &a);
    return (0);
}