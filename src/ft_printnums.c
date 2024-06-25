/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenow <agenow@stdent.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:48:16 by agenow            #+#    #+#             */
/*   Updated: 2024/05/22 11:52:19 by agenow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int		count;
	long	nbr;

	nbr = (long) n;
	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count += ft_printchar('-');
	}
	if (nbr > 9)
		count += ft_printnbr(nbr / 10);
	count += ft_printchar((int)(nbr % 10 + 48));
	return (count);
}

int	ft_printuint(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_printuint(n / 10);
	count += ft_printchar((char)(n % 10 + 48));
	return (count);
}
