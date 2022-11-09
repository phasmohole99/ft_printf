/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:13:00 by mrital-           #+#    #+#             */
/*   Updated: 2022/11/08 18:25:55 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//write one charct
// function for one charactere
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

//write any string
// function for string
int	ft_putstr(char *r)
{
	int	len;

	if (!r)
		r = "(null)";
	len = 0;
	while (*r)
		len += write(1, &(*r++), 1);
	return (len);
}

//transform number to charctere + '0'
// and calcul len array
// conditions nb == max int || nb > 9 || nb < 0
// function for decimal
// nb = max int && nb < 0 == *-
//and printf ('-' is signe) first in string
int	ft_putnbr(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_uns(unsigned int n)
{
	int	len;

	len = 0;
	len += ft_putnbr(n);
	return (len);
}
