/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_unsigned_digital.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:05:24 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/16 17:10:59 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_format_unsigned_digital(unsigned int num)
{
	if (num >= 10)
	{
		ft_format_unsigned_digital(num / 10);
		ft_format_unsigned_digital(num % 10);
	}
	if (num < 10)
	{
		num += '0';
		write(1, &num, 1);
	}
}
