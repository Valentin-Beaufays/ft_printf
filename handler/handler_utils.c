/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 21:08:05 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/03/10 21:36:45 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	handle_prec(char **str, int prec)
{
	size_t	len;
	char	*new;

	len = ft_strlen(*str);
	if (prec >= 0 && (size_t)prec > len)
	{
		if (!(new = malloc(sizeof(**str) * (prec + 1))))
			return (0);
		ft_memset(new, '0', prec - len);
		ft_memcpy(new + (prec - len), *str, len);
		new[prec] = 0;
		free(*str);
		*str = new;
	}
	return (1);
}

int	handle_flag(char **str, t_param *param)
{
	size_t	len;
	char	*new;
	char	c;

	len = ft_strlen(*str);
	if ((size_t)(param->width) > len)
	{
		if (!(new = malloc(sizeof(**str) * (param->width + 1))))
			return (0);
		c = (param->flag == 1) ? '0' : ' ';
		ft_memset(new, c, param->width);
		if (param->flag == 2)
			ft_memcpy(new, *str, len);
		else
			ft_memcpy(new + (param->width - len), *str, len);
		new[param->width] = 0;
		free(*str);
		*str = new;
	}
	return (1);
}

int	handle_int_prec(char **str, t_param *param)
{
	char *new;
	char *tmp;
	char *sign;

	if (param->prec >= 0)
	{
		sign = "";
		if ((*str)[0] == '-')
		{
			tmp = ft_strdup((*str) + 1);
			sign = "-";
		}
		else
			tmp = ft_strdup(*str);
		if (!handle_prec(&tmp, param->prec) || !(new = ft_strjoin(sign, tmp)))
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		free(*str);
		*str = new;
	}
	return (1);
}

int	handle_int_flag(char **str, t_param *param)
{
	char	*new;
	char	*sign;
	char	*tmp;

	if (param->flag == 1)
	{
		sign = "";
		if ((*str)[0] == '-')
		{
			param->width = (param->width > 0) ? param->width - 1 : 0;
			tmp = ft_strdup((*str) + 1);
			sign = "-";
		}
		else
			tmp = ft_strdup(*str);
		if (!handle_flag(&tmp, param) || !(new = ft_strjoin(sign, tmp)))
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		free(*str);
		*str = new;
	}
	return ((handle_flag(str, param)));
}

int	handle_ptr_flag(char **str, t_param *param)
{
	char *new;

	if (param->flag == 1)
	{
		param->width = (param->width >= 2) ? param->width - 2 : 0;
		if (!handle_flag(str, param) || !(new = ft_strjoin("0x", *str)))
			return (0);
	}
	else
	{
		new = ft_strjoin("0x", *str);
		handle_flag(&new, param);
	}
	free(*str);
	*str = new;
	return (1);
}
