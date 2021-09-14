/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_digital_neg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:40:31 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 18:00:22 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_digital_neg(int num, const char *format, int *i)
{
	int width;
	int precision;
	int precision_negative;

	num *= -1;
	width = ft_prec_width(format, i) - 1;
	precision = ft_prec_precision(format, i) - ft_numlen_i(num);
	precision_negative = precision;
	if (precision_negative < 0)
		precision_negative -= precision_negative;
	if (width > 0)
		width = precision > 0 ? width - ft_numlen_i(num) - precision : width -
		ft_numlen_i(num);
	while (width >= 0 && width--)
		write(1, " ", 1);
	write(1, "-", 1);
	while (precision > 0 && precision--)
		write(1, "0", 1);
	ft_format_digital(num);
	if (width < 0)
		width = width * -1 - ft_numlen_i(num) - 2 - precision_negative;
	while (width >= 0 && width--)
		write(1, " ", 1);
}
