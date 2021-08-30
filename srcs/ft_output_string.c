/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:12:34 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/30 22:14:02 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_output_string(t_print *tab)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(tab->args, char *);
	if (!s)
		s = "(null)";
	while (s[i])
		tab->tl += write(1, &s[i++], 1);
}
