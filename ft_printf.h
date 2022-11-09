/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrital- <mrital-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:53:30 by mrital-           #+#    #+#             */
/*   Updated: 2022/11/08 22:58:59 by mrital-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *form, ...);
int		ft_putchar(char c);
int		ft_putstr(char *r);
int		ft_putnbr(long nb);
int		ft_adress(unsigned long n);
int		ft_puthexa(unsigned int n, char c);
int		ft_uns(unsigned int n);

#endif