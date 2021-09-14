/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:59:49 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:12:15 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_prec_width(const char *format, int *i)
{
	char	char_width[11];
	int		a;
	int		width;

	ft_bzero(char_width, 11);
	a = 0;
	while (format[*i] != '.')
	{
		char_width[a] = format[*i];
		++*i;
		a++;
	}
	++*i;
	return (width = ft_atoi(char_width));
}
