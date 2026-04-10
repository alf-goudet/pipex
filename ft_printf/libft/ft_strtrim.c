/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:05:36 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:10:54 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, char const *set);

static size_t	get_start(char const *str, char const *set);

static size_t	get_end(char const *str, char const *set, size_t start_i);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trim;
	size_t	start_i;
	size_t	end_i;
	size_t	trim_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_i = get_start(s1, set);
	end_i = get_end(s1, set, start_i);
	if (start_i >= end_i)
		return (ft_strdup(""));
	trim_len = end_i - start_i + 1;
	s1_trim = (char *)malloc(trim_len + 1);
	if (s1_trim == NULL)
		return (NULL);
	ft_memcpy(s1_trim, &s1[start_i], trim_len);
	s1_trim[trim_len] = '\0';
	return (s1_trim);
}

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start(char const *str, char const *set)
{
	size_t	start_i;

	start_i = 0;
	while (str[start_i] != '\0' && is_in_set(str[start_i], set))
		start_i++;
	return (start_i);
}

static size_t	get_end(char const *str, char const *set, size_t start_i)
{
	size_t	end_i;
	size_t	len;

	len = ft_strlen(str);
	if (len == 0)
		return (start_i);
	end_i = len - 1;
	while (end_i >= start_i && is_in_set(str[end_i], set))
		end_i--;
	return (end_i);
}
