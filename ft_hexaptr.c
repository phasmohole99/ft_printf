/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:37:11 by mrital-           #+#    #+#             */
/*   Updated: 2022/11/08 19:51:30 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n, char c)
{
	size_t	len;
	char	*hex;

	len = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_puthexa(n / 16, c);
	len += ft_putchar(hex[(n % 16)]);
	return (len);
}

int	ft_adress(unsigned long n)
{
	size_t	len;
	char	*hex;

	len = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		len += ft_adress(n / 16);
	len += ft_putchar(hex[(n % 16)]);
	return (len);
}
