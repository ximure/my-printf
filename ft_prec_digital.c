/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_digital.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:40:31 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/17 21:06:20 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_prec_digital_2(int width, int num, int precision_neg)
{
	if (width < 0)
		width = width * -1 - ft_numlen_i(num) - precision_neg;
	while (width >= 0 && width--)
		write(1, " ", 1);
}

void	ft_p0_n0_d(int width)
{
	if (width < 0)
		width *= -1;
	while (width > 0)
	{
		write(1, " ", 1);
		width--;
	}
}

int		ft_prec_digital(int num, const char *format, int *i)
{
	int	w;
	int p;
	int	p_n;

	w = ft_prec_width(format, i);
	p = ft_prec_precision(format, i);
	if (num == 0 && p == 0)
	{
		ft_p0_n0_d(w);
		return (0);
	}
	if (p == 0 && w == 0 && num == 0)
		return (0);
	p = p - ft_numlen_i(num);
	p_n = p;
	p_n < 0 ? p_n -= p_n : p;
	if (w > 0)
		w = p > 0 ? w - ft_numlen_i(num) - p : w - ft_numlen_i(num);
	while (w >= 0 && w--)
		write(1, " ", 1);
	while (p >= 0 && p--)
		write(1, "0", 1);
	ft_format_digital(num);
	ft_prec_digital_2(w, num, p_n);
	return (0);
}
