/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:31:52 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:57:42 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Brief: Takes two memory areas and copies a given number of bytes of memory
 * from the source area to the destination area.
 *
 * Parameters:
 * - dest: a void pointer to a memory area to copy to.
 * - src: a constant void pointer to a memory area to copy from.
 * - n: The number of bytes of memory to copy from src to dest.
 *
 * Returned value: The function returns a pointer to the destination memory
 * area, after it has recieved the bytes of memory from src.
 *
 * NOTES:
 * - This function will not work properly on memory areas that overlap
 *   anywhere. In such cases, memmove is the function that should be used.
 * - This function also considers the edge case of the number of bytes
 *   to copy being 0 (i.e. nothing to copy). In this special case, the function
 *   will simply return the empty destination memory area, without any prior
 *   operations being done.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		*(dest_ptr + i) = *(src_ptr + i);
		i++;
	}
	return (dest);
}
