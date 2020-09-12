/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:03:30 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/03/05 21:05:40 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parser(const char *str, va_list *args, int *len)
{
	t_param	param;
	int		size;
	int		err;

	err = 0;
	init_struct(&param);
	size = get_arg(str, args, &param);
	if (size > 0)
		err = handler(args, &param);
	if (err > 0)
		*len += err;
	return (((err == -1) ? -1 : size));
}
