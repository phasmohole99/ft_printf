/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:53:39 by mrital-           #+#    #+#             */
/*   Updated: 2022/11/09 12:49:26 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if you have t3am9 mzn f variadic func mzn 
// entre "https://raw.githubusercontent.com/wiki/hjl-tools/x86-psABI/x86-64-psABI-1.0.pdf"
// bda mn page 55 
// printf all specials ::  %% double pourcentage print one % just ||
// %s is printf list charactere || %c printf one charactere
// ||%d printf all decimale
// ||%u printf unsigned  
//|| %p printf adresse || %x hexa decimal little || %X printf hexa decimal big

int	ft_func(va_list ptr, const char sp)
{
	int	len;

	len = 0;
	if (sp == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (sp == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (sp == 'd' || sp == 'i')
		len += ft_putnbr(va_arg(ptr, int));
	else if (sp == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_adress(va_arg(ptr, long));
	}
	else if (sp == 'x' || sp == 'X')
		len += ft_puthexa(va_arg(ptr, long), sp);
	else if (sp == 'u')
		len += ft_uns(va_arg(ptr, int));
	else if (sp == '%')
		len += ft_putchar('%');
	return (len);
}

/*
figure to va_list --> stocked in vectore registers in proccess
vectore regiters --> 
≠**************************≠
* typedef struct {         *
* unsigned int gp_offset;  *
* unsigned int fp_offset;  *
* void *overflow_arg_area; *
* void *reg_save_area;     *
* } va_list[1];            *
≠**************************≠
*/
// format printf 
int	ft_printf(const char *form, ...)
{
	va_list	ptr;
	size_t	i;
	long	len;

	va_start(ptr, form);
	len = 0;
	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
		{
			len += ft_func(ptr, form[i + 1]);
			i++;
		}
		else
			len += ft_putchar(form[i]);
		i++;
	}
	va_end(ptr);
	return (len);
}
