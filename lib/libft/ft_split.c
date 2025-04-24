/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:57:17 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:57:19 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*del(char **s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free (s);
	return (NULL);
}

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*fill_letter(const char *s, char c)
{
	int			lettercount;
	int			i;
	char		*string;
	const char	*copied;

	i = 0;
	lettercount = 0;
	copied = s;
	while (*s != c && *s)
	{
		lettercount++;
		s++;
	}
	string = (char *) malloc (sizeof(char) * (lettercount + 1));
	if (!string)
		return (NULL);
	while (i < lettercount)
	{
		string[i++] = *copied++;
	}
	string[i] = 0;
	return (string);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		wordcount;

	i = 0;
	wordcount = count_word(s, c);
	strings = (char **) malloc (sizeof(char *) * (wordcount + 1));
	if (!strings)
		return (NULL);
	while (i < wordcount)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strings[i] = fill_letter(s, c);
			if (!strings[i])
				return (del(strings, i));
			while (*s && *s != c)
				s++;
		}
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
