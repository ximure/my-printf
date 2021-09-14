/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:05:24 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:11:14 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_numlen(unsigned int u_num, int num, const char *format, int *i)
{
	int a;

	a = 1;
	if (format[*i] == 'u')
		while (u_num /= 10)
			a++;
	else
	{
		if (num < 0)
		{
			num *= -1;
			a += 1;
		}
		while (num /= 10)
			a++;
	}
	return (a);
}
