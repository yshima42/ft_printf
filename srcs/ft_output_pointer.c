/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:12:30 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/12 13:38:17 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				len;

	len = 1;
	base_len = ft_strlen(base);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (len);
	}
	if (n >= base_len)
	{
		len += ft_putnbr_base(n / base_len, base);
		ft_putchar_fd(base[n % base_len], 1);
	}
	else if (n < base_len)
		ft_putchar_fd(base[n], 1);
	return (len);
}

void	ft_output_pointer(t_print *tab)
{
	unsigned long	ans;

	ans = (unsigned long)va_arg(tab->args, void *);
	tab->tl += write(1, "0x", 2);
	tab->tl += ft_putnbr_base(ans, "0123456789abcdef");
}
