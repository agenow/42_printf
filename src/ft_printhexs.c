/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenow <agenow@stdent.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:56:31 by agenow            #+#    #+#             */
/*   Updated: 2024/05/22 11:52:15 by agenow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printshex(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
		count += ft_printshex(n / 16);
	count += ft_printchar(base[n % 16]);
	return (count);
}

int	ft_printlhex(unsigned int n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n > 15)
		count += ft_printlhex(n / 16);
	count += ft_printchar(base[n % 16]);
	return (count);
}

int	ft_printptr(unsigned long long n, int flag)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (!n || n == 0)
		return (ft_printf("(nil)"));
	if (flag == 1)
		count += ft_printf("0x");
	if (n < 0)
		return (-1);
	if (n > 15)
		count += ft_printptr(n / 16, 0);
	count += ft_printchar(base[n % 16]);
	return (count);
}
