/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:26:50 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/09/09 16:32:16 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_flags(const char *str, t_param *param)
{
	int	size;

	size = 0;
	while (str[size] && ft_strchr("0-", str[size]))
	{
		if (str[size] == '0' && param->flag == 0)
			param->flag = 1;
		if (str[size] == '-')
			param->flag = 2;
		size++;
	}
	return (size);
}

int	get_width(const char *str, va_list *args, t_param *param)
{
	int	size;
	int	star;

	size = 0;
	if (str[size] == '*')
	{
		star = va_arg(*args, int);
		if (star < 0)
		{
			param->flag = 2;
			param->width = star * -1;
		}
		else
			param->width = star;
		size++;
	}
	else
	{
		param->width = ft_atoi(str);
		while (ft_isdigit(str[size]))
			size++;
	}
	return (size);
}

int	get_prec(const char *str, va_list *args, t_param *param)
{
	int	size;
	int	star;

	size = 0;
	while (str[size] == '.')
		size++;
	if (str[size] == '*')
	{
		star = va_arg(*args, int);
		param->prec = (star >= 0) ? star : -1;
		size++;
	}
	else if (ft_isdigit(str[size]))
	{
		param->prec = ft_atoi(str + size);
		while (ft_isdigit(str[size]))
			size++;
	}
	else
		param->prec = 0;
	return (size);
}

int	get_arg(const char *str, va_list *args, t_param *param)
{
	int	size;

	size = 1;
	while (str[size] && !(ft_strchr("csdiupxX%", str[size])))
	{
		if (ft_strchr("0-", str[size]))
			size += get_flags(str + size, param);
		else if (ft_isdigit(str[size]) || str[size] == '*')
			size += get_width(str + size, args, param);
		else if (str[size] == '.')
			size += get_prec(str + size, args, param);
		else
			return (0);
	}
	if (str[size] != 0)
	{
		param->type = str[size];
		return (size);
	}
	return (0);
}
