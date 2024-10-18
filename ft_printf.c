/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:08:34 by moelkama          #+#    #+#             */
/*   Updated: 2023/01/08 15:09:07 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_printf2(const char *str, va_list v)
{
	if (str[1] == 'c')
		return (ft_putchar(va_arg(v, int)));
	else if (str[1] == 's')
		return (ft_putstr(va_arg(v, char *)));
	else if (str[1] == 'p')
	{
		ft_putstr("0x");
		return (ft(va_arg(v, unsigned long), "0123456789abcdef", 16, 2));
	}
	else if (str[1] == 'd' || str[1] == 'i')
		return (ft_putnbr_base(va_arg(v, int), "0123456789"));
	else if (str[1] == 'u')
		return (ft_putnbr_base(va_arg(v, unsigned int), "0123456789"));
	else if (str[1] == 'x')
		return (ft_putnbr_base(va_arg(v, unsigned int), "0123456789abcdef"));
	else if (str[1] == 'X')
		return (ft_putnbr_base(va_arg(v, unsigned int), "0123456789ABCDEF"));
	return (ft_putchar(str[1]));
}

int	ft_printf(const char *str, ...)
{
	va_list	variable;
	int		len;
	int		i;

	va_start(variable, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += ft_printf2(&str[i], variable);
			i += 2;
		}
		else if (str[i] != '%')
			len += ft_putchar(str[i++]);
		else
			i++;
	}
	va_end(variable);
	return (len);
}
