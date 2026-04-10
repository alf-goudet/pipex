/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:33:15 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:01:38 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (1)
	{
		if (*p == (unsigned char)c)
			return (p);
		else if (*p == '\0')
			break ;
		else
			p++;
	}
	return (NULL);
}
