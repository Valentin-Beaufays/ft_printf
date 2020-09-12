/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:39:55 by vbeaufay          #+#    #+#             */
/*   Updated: 2019/11/05 18:44:17 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		freeall(char **s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static size_t	word_counter(char const *s, char c)
{
	size_t	count;
	int		is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static char		**get_res(char const *s, char c)
{
	size_t	count;
	char	**res;

	count = word_counter(s, c);
	if (!(res = malloc(sizeof(*res) * (count + 1))))
		return (0);
	res[count] = 0;
	return (res);
}

static char		*get_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!(word = malloc(sizeof(*word) * (len + 1))))
		return (0);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	if (!(res = get_res(s, c)))
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			if (!(res[word++] = get_word(s + i, c)))
			{
				freeall(res, word);
				return (0);
			}
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}
