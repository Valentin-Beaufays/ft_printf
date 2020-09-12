/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:55:59 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/09/09 15:56:39 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_uint(va_list *args, t_param *param)
{
	char	*str;

	param->flag = (param->prec >= 0 && param->flag == 1) ? 0 : param->flag;
	if (!(str = ft_utoa(va_arg(*args, unsigned int))))
		return (-1);
	if (str[0] == '0' && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (!handle_prec(&str, param->prec) || !handle_flag(&str, param))
	{
		free(str);
		return (-1);
	}
	return (writer(str, ft_strlen(str)));
}

int	handle_hex(va_list *args, t_param *param)
{
	char	*str;
	char	*base;

	base = (param->type == 'X') ? BASE_16 : BASE_16_MIN;
	param->flag = (param->prec >= 0 && param->flag == 1) ? 0 : param->flag;
	if (!(str = ft_utoa_base(va_arg(*args, unsigned int), base)))
		return (-1);
	if (str[0] == '0' && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (!handle_prec(&str, param->prec) || !handle_flag(&str, param))
	{
		free(str);
		return (-1);
	}
	return (writer(str, ft_strlen(str)));
}

int	handle_ptr(va_list *args, t_param *param)
{
	char	*str;

	param->flag = (param->prec >= 0 && param->flag == 1) ? 0 : param->flag;
	if (!(str = ft_lutoa_base(va_arg(*args, unsigned long int), BASE_16_MIN)))
		return (-1);
	if (*str == '0' && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (!handle_prec(&str, param->prec) || !handle_ptr_flag(&str, param))
	{
		free(str);
		return (-1);
	}
	return (writer(str, ft_strlen(str)));
}
