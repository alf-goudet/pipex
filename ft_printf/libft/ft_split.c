/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:30:58 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:00:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);

static char		**extract_words(char **split_s, char const *s, char c);

static size_t	find_word(char const *s, size_t *i, size_t *start, char c);

static void		*free_whole_array(char **arr, size_t word_n);

char	**ft_split(char const *s, char c)
{
	char		**split_s;
	size_t		word_count;

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0')
	{
		split_s = (char **)malloc(1 * sizeof(char *));
		if (split_s == NULL)
			return (NULL);
		split_s[0] = NULL;
		return (split_s);
	}
	word_count = count_words(s, c);
	split_s = (char **)malloc((word_count + 1) * sizeof(char *));
	if (split_s == NULL)
		return (NULL);
	split_s = extract_words(split_s, s, c);
	return (split_s);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		in_word_before;

	count = 0;
	i = 0;
	in_word_before = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !in_word_before)
		{
			count++;
			in_word_before = 1;
		}
		else if (s[i] == c)
			in_word_before = 0;
		i++;
	}
	return (count);
}

static char	**extract_words(char **split_s, char const *s, char c)
{
	char	*word;
	size_t	s_idx;
	size_t	split_idx;
	size_t	word_start;
	size_t	word_len;

	s_idx = 0;
	split_idx = 0;
	while (s[s_idx] != '\0')
	{
		word_len = find_word(s, &s_idx, &word_start, c);
		if (word_len > 0)
		{
			word = (char *)malloc(word_len + 1);
			if (word == NULL)
				return (free_whole_array(split_s, split_idx));
			ft_strlcpy(word, &s[word_start], word_len + 1);
			split_s[split_idx] = word;
			split_idx++;
		}
	}
	split_s[split_idx] = NULL;
	return (split_s);
}

static size_t	find_word(char const *s, size_t *i, size_t *start, char c)
{
	size_t	len;

	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	*start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	len = *i - *start;
	return (len);
}

static void	*free_whole_array(char **arr, size_t word_n)
{
	size_t	k;

	if (arr == NULL)
		return (NULL);
	k = 0;
	while (k < word_n)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
	return (NULL);
}
