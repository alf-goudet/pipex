/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:20:30 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:04:07 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;
	size_t	tot_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tot_len = s1_len + s2_len;
	new_s = (char *)malloc(tot_len + 1);
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, s1, s1_len);
	ft_memcpy(&new_s[s1_len], s2, s2_len);
	new_s[tot_len] = '\0';
	return (new_s);
}
