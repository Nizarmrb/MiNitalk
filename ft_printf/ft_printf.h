/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelmrabe <nelmrabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:33:40 by nelmrabe          #+#    #+#             */
/*   Updated: 2022/12/14 10:10:21 by nelmrabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		put_unsigned_nbr(unsigned int num);
int		ft_putstr(char *s);
int		ft_hexa(unsigned int nbr);
int		ft_hexxa(unsigned int nbr);
int		ft_putmemoryaddress(unsigned long nbr);
int		ft_x(unsigned	long int nbr);

#endif 