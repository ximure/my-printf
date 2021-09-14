/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_width_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:06:19 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 20:56:41 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_format_width_char(char *s, const char *format, int *i)
{
	char	temp[11];
	int		width;
	int		a;

	a = 0;
	ft_bzero(temp, 11);
	while (format[*i] != 's')
	{
		temp[a] = format[*i];
		a++;
		++*i;
	}
	if (s == NULL)
		s = "(null)";
	width = ft_atoi(temp) - ft_strlen(s);
	if (temp[0] == '-')
		width = ((ft_atoi(temp) + ft_strlen(s)) * -1 + 1);
	while (width != 0 && width > 0 && width-- && temp[0] != '-')
		write(1, " ", 1);
	ft_format_string(s);
	while (temp[0] == '-' && width-- && width >= 0)
		write(1, " ", 1);
	return (0);
}