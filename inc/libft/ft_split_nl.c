/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_nl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:23:37 by cedmulle          #+#    #+#             */
/*   Updated: 2024/01/07 15:45:08 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str)
{
	int	count;
	int	new_line;

	count = 0;
	new_line = 1;
	while (*str)
	{
		if (*str == '\n')
		{
			count++;
			new_line = 1;
			if (*(str + 1) == '\n')
				count++;
		}
		else
			new_line = 0;
		str++;
	}
	return (count + new_line);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	split_words(char **result, char *s)
{
	t_split	split;

	split.i = -1;
	split.start = 0;
	split.k = 0;
	while (s[++split.i])
	{
		if (s[split.i] == '\n' && s[split.i + 1] == '\n')
		{
			if (split.i > split.start)
				result[split.k++] = word_dup(s, split.start, split.i);
			result[split.k++] = word_dup("\n", 0, 1);
			split.start = split.i + 2;
			split.i++;
		}
		else if (s[split.i] == '\n')
		{
			if (split.i > split.start)
				result[split.k++] = word_dup(s, split.start, split.i);
			split.start = split.i + 1;
		}
	}
	if (split.start < split.i)
		result[split.k++] = word_dup(s, split.start, split.i);
	result[split.k] = NULL;
}

char	**ft_split_nl(char *s)
{
	char	**result;

	result = (char **)malloc((count_words(s) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	split_words(result, s);
	return (result);
}
