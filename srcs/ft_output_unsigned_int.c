/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:12:40 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/11 12:12:40 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

size_t	ft_getsize(long long n_long)
{
	size_t	size;

	size = 0;
	if (n_long < 0)
		size++;
	while (n_long / 10)
	{
		size++;
		n_long = n_long / 10;
	}
	size++;
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	char		*ans;
	long long	n_long;
	size_t		size;

	n_long = n;
	size = ft_getsize(n_long);
	ans = (char *)malloc(sizeof(char) * (size + 1));
	if (!ans)
		return (NULL);
	if (n_long == 0)
		ans[0] = '0';
	ans[size] = '\0';
	size--;
	while (n_long > 0)
	{
		ans[size] = n_long % 10 + '0';
		n_long /= 10;
		size--;
	}
	return (ans);
}

void	ft_output_unsigned_int(t_print *tab)
{
	int				i;
	unsigned int	ans_i;
	char			*ans_c;

	i = 0;
	ans_i = va_arg(tab->args, unsigned int);
	if (!ans_i)
	{
		tab->tl += write(1, "0", 1);
		return ;
	}
	ans_c = ft_uitoa(ans_i);
	if (!ans_c)
		return ;
	while (ans_c[i])
		tab->tl += write(1, &ans_c[i++], 1);
	free(ans_c);
}
