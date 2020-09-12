/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:57:13 by vbeaufay          #+#    #+#             */
/*   Updated: 2020/03/11 15:49:32 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# ifndef BASE_10
#  define BASE_10 "0123456789"
# endif
# ifndef BASE_16
#  define BASE_16 "0123456789ABCDEF"
# endif
# ifndef BASE_16_MIN
#  define BASE_16_MIN "0123456789abcdef"
# endif

typedef	struct	s_param
{
	int			flag;
	int			width;
	int			prec;
	char		type;
}				t_param;

int				ft_printf(const char *str, ...);
int				init_struct(t_param *lst);
int				parser(const char *str, va_list *args, int *len);
int				get_arg(const char *str, va_list *args, t_param *param);
int				handler(va_list *args, t_param *param);
int				handle_flag(char **str, t_param *param);
int				handle_prec(char **str, int prec);
int				handle_int_prec(char **str, t_param *param);
int				handle_int_flag(char **str, t_param *param);
int				handle_ptr_flag(char **str, t_param *param);
int				handle_char(va_list *args, t_param *param);
int				handle_str(va_list *args, t_param *param);
int				handle_int(va_list *args, t_param *param);
int				handle_uint(va_list *args, t_param *param);
int				handle_hex(va_list *args, t_param *param);
int				handle_ptr(va_list *args, t_param *param);
int				writer(char *str, int len);

#endif
