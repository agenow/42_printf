/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenow <agenow@stdent.42berlin.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:06:42 by agenow            #+#    #+#             */
/*   Updated: 2024/05/22 11:52:16 by agenow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printchar(int c); 
int	ft_printstr(char *str);
int	ft_printnbr(int n);
int	ft_printuint(unsigned int n);
int	ft_printshex(unsigned int n);
int	ft_printlhex(unsigned int n);
int	ft_printptr(unsigned long long n, int flag);
int	ft_modifier(va_list args, char mod);
int	ft_printf(const char *str, ...);
int	ft_modsanitizer(char mod);

#endif
