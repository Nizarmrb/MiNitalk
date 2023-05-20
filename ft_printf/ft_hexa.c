/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:01:23 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/12/23 19:06:30 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned	int nbr)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_hexa(nbr / 16);
	i += ft_putchar(hex[nbr % 16]);
	return (i);
}

int	ft_hexxa(unsigned	int nbr)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (nbr >= 16)
		i += ft_hexxa(nbr / 16);
	i += ft_putchar(hex[nbr % 16]);
	return (i);
}
