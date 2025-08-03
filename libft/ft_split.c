/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:45:23 by iduman            #+#    #+#             */
/*   Updated: 2025/06/03 18:29:07 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(char const *s, char c)
{
	size_t		count;
	signed char	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	check_memory(char **result, size_t word)
{
	if (!result[word])
	{
		while (word > 0)
			free(result[--word]);
		free(result);
		return (1);
	}
	return (0);
}

static char	**setter(char **result, const char *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	start;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[word] = ft_substr(s, start, i - start);
			if (check_memory(result, word))
				return ((char **) NULL);
			word++;
		}
		else
			i++;
	}
	result[word] = (NULL);
	return (result);
}

/*
The ft_split function splits a string into an array of strings
based on a specified delimiter character.
It counts the number of words in the string,
allocates memory for the array of strings,
and fills the array with the individual words.
Input:
    char const *s: Pointer to the string to be split.
    char c: The delimiter character used to split the string.
Output:
    char**: Pointer to an array of strings (words)
            split from the input string.
            The last element of the array is
            NULL to indicate the end of the array.
            If the input string is NULL, it returns NULL.
            If memory allocation fails, it returns NULL.
*/
char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return ((char **) NULL);
	word_count = word_counter(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return ((char **) NULL);
	return (setter(result, s, c));
}
