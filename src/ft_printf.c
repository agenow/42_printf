/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenow <agenow@stdent.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:16:54 by agenow            #+#    #+#             */
/*   Updated: 2024/05/22 11:49:35 by agenow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// we skip the escape char and then we are continuing afterwards
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	(void) args;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_modsanitizer(str[i + 1]) == 1)
				len += ft_modifier(args, str[++i]);
			else
				return (-1);
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_modsanitizer(char mod)
{
	char	*base;
	int		i;

	base = "cspdiuxX%";
	i = 0;
	while (base[i])
	{
		if (mod == base[i])
			return (1);
		i++;
	}
	return (-1);
}

// if mod is some other char (e.g. w or \0 then I'm not handeling it
int	ft_modifier(va_list args, char mod)
{
	if (mod == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (mod == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (mod == 'p')
		return (ft_printptr(va_arg(args, unsigned long long), 1));
	else if (mod == 'd' || mod == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (mod == 'u')
		return (ft_printuint(va_arg(args, unsigned int)));
	else if (mod == 'x')
		return (ft_printshex(va_arg(args, unsigned long)));
	else if (mod == 'X')
		return (ft_printlhex(va_arg(args, unsigned long)));
	else if (mod == '%')
		return (ft_printchar('%'));
	return (0);
}
