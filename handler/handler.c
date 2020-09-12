/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:17:04 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/03/10 21:35:51 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handler(va_list *args, t_param *param)
{
	int	ret;

	ret = 0;
	if (param->type == 'c' || param->type == '%')
		ret = handle_char(args, param);
	else if (param->type == 's')
		ret = handle_str(args, param);
	else if (param->type == 'p')
		ret = handle_ptr(args, param);
	else if (param->type == 'd' || param->type == 'i')
		ret = handle_int(args, param);
	else if (param->type == 'u')
		ret = handle_uint(args, param);
	else if (param->type == 'x' || param->type == 'X')
		ret = handle_hex(args, param);
	return (ret);
}
