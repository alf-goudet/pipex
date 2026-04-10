/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:23:37 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:11:09 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_substr - Allocate a substring in memory
 *
 * Description:
 * 	The ft_substr function allocates at most len bytes of memory and
 * returns a substring of the string s, starting at position start. It uses
 * ft_strlen for calculating the length, malloc for memory allocation, and
 * ft_strlcpy for copying the characters of the string into the substring.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	sub_s_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub_s = ft_strdup("");
		return (sub_s);
	}
	if (s_len - start < len)
		sub_s_len = s_len - start;
	else
		sub_s_len = len;
	sub_s = (char *)malloc(sub_s_len + 1);
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, &s[start], sub_s_len + 1);
	return (sub_s);
}
