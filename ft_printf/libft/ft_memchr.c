/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:09:10 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:56:49 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_memchr - Scan a memory area for a certain byte.
 *
 * Description:
 * ft_memchr() searches the first n bytes of the memory area pointed to by s
 * to try to find the first instance of the byte c. Both c and the bytes of the
 * memory area pointed to by s will be interpreted as unsigned char.
 *
 * Parameters:
 * - s: A constant void pointer to the memory area to search.
 * - c: The byte to search for in s (given as an integer).
 * - n: The max number of bytes to search from the begionning of s.
 *
 * Return Value:
 * The function will return a pointer to the byte in memory if it was found. If
 * not, it will return NULL.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*byte_ptr;

	byte_ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (byte_ptr[i] == (unsigned char)c)
			return ((void *)(byte_ptr + i));
		i++;
	}
	return (NULL);
}
