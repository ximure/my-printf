/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:49:18 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:11:56 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_handler(const char *format, int *i, va_list args)
{
	int a;

	a = *i;
	while (format[a] != '.')
		a++;
	if (format[a + 1] == '*' || format[a - 1] == '*')
		ft_prec_star_handler(format, i, args);
	else
		ft_prec_nstar_handler(format, i, args);
}
