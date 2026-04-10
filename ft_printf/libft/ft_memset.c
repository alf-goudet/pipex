/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:05:48 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:58:47 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	const_byte;
	unsigned char	*buffer;

	buffer = (unsigned char *)s;
	const_byte = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*(buffer + i) = const_byte;
		i++;
	}
	return (s);
}
