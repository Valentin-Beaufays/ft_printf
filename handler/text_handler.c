/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:29:53 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/03/10 20:23:24 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

int	handle_str(va_list *args, t_param *param)
{
	char *str;

	if (!(str = va_arg(*args, char *)))
	{
		if (!(str = (ft_strdup("(null)"))))
			return (-1);
	}
	else if (!(str = ft_strdup(str)))
		return (-1);
	if (param->prec >= 0 && ft_strlen(str) > (size_t)(param->prec))
		str[param->prec] = 0;
	if (!(handle_flag(&str, param)))
	{
		free(str);
		return (-1);
	}
	return (writer(str, ft_strlen(str)));
}

int	handle_char(va_list *args, t_param *param)
{
	char	*str;
	size_t	len;
	char	c;
	char	add;

	c = (param->type == '%') ? '%' : (char)va_arg(*args, int);
	len = (param->width > 1) ? param->width : 1;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (-1);
	add = (param->flag == 1) ? '0' : ' ';
	ft_memset(str, add, param->width);
	if (param->flag == 2)
		str[0] = c;
	else
		str[len - 1] = c;
	str[len] = 0;
	return (writer(str, len));
}
