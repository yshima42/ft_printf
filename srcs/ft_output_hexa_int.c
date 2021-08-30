/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_hexa_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:12:15 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/30 22:14:23 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_numlen_base(unsigned long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i += 1;
		return (i);
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_itoa_base(char *str, unsigned long n, int base, int c)
{
	int		i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		if (base > 10 && (n % base >= 10))
			str[i++] = (n % base) - 10 + c;
		else
			str[i++] = (n % base) + '0';
		n /= base;
	}
	str[i] = '\0';
	return (str);
}

void	ft_output_hexa_int(t_print *tab, int c)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(tab->args, unsigned int);
	if (!j)
	{
		tab->tl += write(1, "0", 1);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	while (num && len-- > 0)
		tab->tl += write(1, &num[len], 1);
	free(num);
}
