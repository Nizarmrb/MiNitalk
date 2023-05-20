/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:06:29 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/12/23 20:20:57 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_x(unsigned	long int nbr)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_x(nbr / 16);
	i += ft_putchar(hex[nbr % 16]);
	return (i);
}

int	ft_putmemoryaddress(unsigned long nbr)
{
	int	c;

	c = ft_putstr("0x");
	c += (ft_x(nbr));
	return (c);
}
