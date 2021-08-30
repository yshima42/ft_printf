/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:11:52 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/11 13:47:21 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_print
{
	va_list		args;
	int			tl;
}				t_print;

int		ft_printf(const char *format, ...);
void	ft_output_char(t_print *tab);
int		ft_numlen_base(unsigned long n, int base);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);
void	ft_output_hexa_int(t_print *tab, int c);
void	ft_output_int(t_print *tab);
int		ft_putnbr_base(unsigned long n, char *base);
void	ft_output_pointer(t_print *tab);
void	ft_output_string(t_print *tab);
size_t	ft_getsize(long long n_long);
char	*ft_uitoa(unsigned int n);
void	ft_output_unsigned_int(t_print *tab);

#endif