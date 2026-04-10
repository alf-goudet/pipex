/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:50:35 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:09:31 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s + ft_strlen(s);
	while (p >= (char *)s)
	{
		if (*p == (char)c)
			return (p);
		p--;
	}
	return (NULL);
}
