/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sflags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxoo <nxoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:44:07 by nxoo              #+#    #+#             */
/*   Updated: 2022/09/28 18:11:50 by nxoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/main.h"

void	put_x(void *n)
{
	flag_c(LOWERHEXA[(int)n % 16]);
}


void	put_X(void *n)
{
	flag_c(UPPERHEXA[(int)n % 16]);
}