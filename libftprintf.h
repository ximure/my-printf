/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarei <tmarei@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:32:59 by tmarei            #+#    #+#             */
/*   Updated: 2021/01/17 21:11:32 by tmarei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_format_x(unsigned int dec, const char *format, int *i);
void	ft_format_unsigned_digital(unsigned int num);
void	ft_format_width(va_list args, const char *format, int *i);
void	ft_format_width_int(int num, const char *format, int *i);
int		ft_prec_string(const char *format, int *i, char *str);
int		ft_prec_int_u(const char *format, int *i, unsigned int num);
int		ft_numlen(unsigned int u_num, int num, const char *format, int *i);
void	ft_format_width_character(int c, const char *format, int *i);
int		ft_format_width_char(char *s, const char *format, int *i);
void	ft_format_width_x(unsigned int dec, const char *format, int *i);
int		ft_bzero(char *array, size_t n);
int 	ft_atoi(const char *str);
int		ft_prec_width(const char *format, int *i);
void	ft_format_digital(int n);
void 	ft_format_string(char *s);
void 	ft_putchar(const char c);
int 	ft_strlen(const char *str);
int		ft_numlen_i(int num);
void	ft_prec_star_handler(const char *format, int *i, va_list args);
void	ft_prec_nstar_handler(const char *format, int *i, va_list args);
int		ft_prec_digital(int num, const char *format, int *i);
void	ft_prec_digital_handler(const char *format, int *i, int num);
int		ft_prec_precision(const char *format, int *i);
void    ft_prec_string_star(const char *format, int *i, va_list args, int a);
int		ft_prec_digital_star_2(const char *format, int a);
void	ft_prec_digital_star(const char *format, int *i, va_list args, int a);
void	ft_prec_digital_neg(int num, const char *format, int *i);
void	ft_prec_handler(const char *format, int *i, va_list args);

#endif
