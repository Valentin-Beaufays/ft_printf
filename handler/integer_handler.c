/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 11:41:32 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/03/10 20:54:55 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_int(va_list *args, t_param *param)
{
	char	*str;
	int		nbr;

	nbr = va_arg(*args, int);
	param->flag = (param->flag == 1 && param->prec >= 0) ? 0 : param->flag;
	if (!(str = ft_itoa(nbr)))
		return (-1);
	if (str[0] == '0' && param->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (!(handle_int_prec(&str, param))
		|| !(handle_int_flag(&str, param)))
	{
		free(str);
		return (-1);
	}
	return (writer(str, ft_strlen(str)));
}
