/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:06:04 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/12/30 17:02:35 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char const c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	detect_format(char format, va_list	args)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (format == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		counter += ft_putmemoryaddress(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		counter += put_unsigned_nbr(va_arg(args, unsigned int));
	else if (format == 'x')
		counter += ft_hexa(va_arg(args, unsigned int));
	else if (format == 'X')
		counter += ft_hexxa(va_arg(args, unsigned int));
	else if (format == '%')
		counter += ft_putchar(format);
	else
		counter += ft_putchar(format);
	return (counter);
}

int	ft_printf(const	char *format, ...)
{
	int			counter;
	va_list		args;

	va_start(args, format);
	counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			counter += detect_format(*format, args);
		}
		else
			counter += ft_putchar(*format);
		if (*format == '\0')
			break ;
		format++;
	}
	return (counter);
}
