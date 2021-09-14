/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_width_character.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:06:19 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:10:55 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_width_character(int c, const char *format, int *i)
{
	int		a;
	char	temp[11];
	int		width;

	a = 0;
	ft_bzero(temp, 11);
	while (format[*i] != 'c')
	{
		temp[a] = format[*i];
		a++;
		++*i;
	}
	width = ft_atoi(temp) - 1;
	if (temp[0] == '-')
		width = width * -1 - 1;
	while (width != 0 && width > 0 && width-- && temp[0] != '-')
		write(1, " ", 1);
	ft_putchar(c);
	while (temp[0] == '-' && width--)
		write(1, " ", 1);
}
