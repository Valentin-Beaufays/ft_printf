/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:56:58 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/03/10 21:33:17 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		while (*str && *str != '%')
		{
			ft_putchar(*str);
			len++;
			str++;
		}
		if (*str == '%')
		{
			if ((size = parser(str, &args, &len)) == -1)
				return (-1);
			if (size == 0)
				ft_putchar(*str);
			str += size + 1;
		}
	}
	va_end(args);
	return (len);
}
