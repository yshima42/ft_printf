/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:12:08 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/11 12:24:16 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_output_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->tl += write(1, &c, 1);
}
