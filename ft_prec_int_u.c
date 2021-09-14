/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_int_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ximure <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 18:26:15 by ximure            #+#    #+#             */
/*   Updated: 2021/01/16 18:26:19 by ximure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_p0_n0(int width)
{
	if (width < 0)
		width *= -1;
	while (width > 0)
	{
		write(1, " ", 1);
		width--;
	}
}

int		ft_numlen_uu(unsigned int num)
{
	int a;

	a = 1;
	while (num /= 10)
		a++;
	return (a);
}

void	ft_prec_int_u_2(int width, unsigned int num, int precision_neg)
{
	if (width < 0)
		width = width * -1 - ft_numlen_uu(num) - precision_neg;
	while (width >= 0 && width--)
		write(1, " ", 1);
}

int		ft_prec_int_u(const char *format, int *i, unsigned int num)
{
	int	w;
	int p;
	int	p_n;

	w = ft_prec_width(format, i);
	p = ft_prec_precision(format, i);
	if (num == 0 && p == 0)
	{
		ft_p0_n0(w);
		return (0);
	}
	if (p == 0 && w == 0 && num == 0)
		return (0);
	p = p - ft_numlen_uu(num);
	p_n = p;
	p_n = p_n < 0 ? p_n - p_n : p;
	if (w > 0)
		w = p > 0 ? w - ft_numlen_uu(num) - p : w - ft_numlen_uu(num);
	while (w >= 0 && w--)
		write(1, " ", 1);
	while (p >= 0 && p--)
		write(1, "0", 1);
	ft_format_unsigned_digital(num);
	ft_prec_int_u_2(w, num, p_n);
	return (0);
}
