/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:31:33 by moelkama          #+#    #+#             */
/*   Updated: 2023/01/09 15:04:57 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft(unsigned long nb, const char *base, int len, int count)
{
	unsigned long	pow;
	unsigned long	n;

	n = nb;
	pow = 1;
	while (n / len != 0)
	{
		pow *= len;
		n /= len;
	}
	while (pow >= 1)
	{
		count += ft_putchar(base[nb / pow]);
		nb %= pow;
		pow /= len;
	}
	return (count);
}

int	ft_putnbr_base(long nb, const char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (nb < 0)
		return (ft(-nb, base, len, ft_putchar('-')));
	return (ft(nb, base, len, 0));
}
