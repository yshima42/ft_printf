/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:44:46 by yshimazu          #+#    #+#             */
/*   Updated: 2021/08/30 22:12:34 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_check_variable(t_print *tab, const char *format, int var)
{
	if (format[var] == 'c')
		ft_output_char(tab);
	else if (format[var] == 's')
		ft_output_string(tab);
	else if (format[var] == 'd' || format[var] == 'i')
		ft_output_int(tab);
	else if (format[var] == 'u')
		ft_output_unsigned_int(tab);
	else if (format[var] == 'p')
		ft_output_pointer(tab);
	else if (format[var] == 'x' || format[var] == 'X')
		ft_output_hexa_int(tab, format[var] - 23);
	else if (format[var] == '%')
		tab->tl += write(1, "%", 1);
	else
		return(var - 1);
	return (var);
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;

	if (!format)
		return (0);
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (0);
	tab->tl = 0;
	va_start(tab->args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_check_variable(tab, format, i + 1);
		else
			tab->tl += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	free(tab);
	return (tab->tl);
}
