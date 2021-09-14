/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:38:47 by ximure            #+#    #+#             */
/*   Updated: 2021/01/16 16:52:33 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_bzero(char *array, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = array;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (*dest);
}
