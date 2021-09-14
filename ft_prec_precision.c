/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:40:31 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:12:04 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_prec_precision(const char *format, int *i)
{
	char	char_precision[11];
	int		a;
	int		precision;

	a = 0;
	ft_bzero(char_precision, 11);
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		char_precision[a] = format[*i];
		++*i;
		a++;
	}
	return (precision = ft_atoi(char_precision));
}
