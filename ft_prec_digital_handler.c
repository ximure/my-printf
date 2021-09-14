/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_digital_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:40:31 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 18:00:02 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_digital_handler(const char *format, int *i, int num)
{
	while (format[*i] == '0')
		++*i;
	if (num < 0)
		ft_prec_digital_neg(num, format, i);
	else
		ft_prec_digital(num, format, i);
}
