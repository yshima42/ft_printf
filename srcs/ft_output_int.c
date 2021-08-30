/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:12:21 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/11 12:12:23 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_output_int(t_print *tab)
{
	int		i;
	int		ans_i;
	char	*ans_c;

	i = 0;
	ans_i = va_arg(tab->args, int);
	if (!ans_i)
	{
		tab->tl += write(1, "0", 1);
		return ;
	}
	ans_c = ft_itoa(ans_i);
	if (!ans_c)
		return ;
	while (ans_i && ans_c[i])
		tab->tl += write(1, &ans_c[i++], 1);
	free(ans_c);
}
