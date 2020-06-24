/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorazon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 07:09:07 by kcorazon          #+#    #+#             */
/*   Updated: 2020/05/08 07:09:09 by kcorazon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_words(char **words, int i)
{
	while (i--)
	{
		free(words[i]);
		words[i] = NULL;
	}
	free(words);
}

static int	get_words_count(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str != c)
			count++;
		while (*str && *str != c)
			str++;
		if (*str)
			str++;
	}
	return (count);
}

static char	*get_word(char *str, char c)
{
	int word_len;

	word_len = 0;
	while (*str && *str != c)
	{
		word_len++;
		str++;
	}
	return (ft_substr(str - word_len, 0, word_len));
}

static char	**get_words(char *str, char c)
{
	int		w_count;
	char	**words;
	char	*word;
	int		i;

	w_count = get_words_count(str, c);
	if (!(words = malloc(sizeof(char *) * (w_count + 1))))
		return (NULL);
	i = 0;
	while (i < w_count)
	{
		while (*str && *str == c)
			str++;
		word = get_word(str, c);
		if (!word)
		{
			free_words(words, i);
			return (NULL);
		}
		words[i] = word;
		str += ft_strlen(words[i]) + 1;
		i++;
	}
	words[i] = NULL;
	return (words);
}

char		**ft_split(char const *s, char c)
{
	char	*s_dup;
	char	**words;

	if (!s)
		return (NULL);
	s_dup = (char *)s;
	words = get_words(s_dup, c);
	return (words);
}
