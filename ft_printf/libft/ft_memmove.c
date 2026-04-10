/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:21:35 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:58:16 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Brief: ft_memmove takes two memory areas, a destination (*dest) and a
 * 	  source (*src), as well as a size_t number n, and copies n bytes from
 * 	  the source area (src) to the destination area (dest). Unlike
 * 	  ft_memcpy, ft_memmove does manage memory overlapping.
 *
 * NOTES:
 * - The function manages memory overlapping by determining three cases:
 *   1. If dest < src: The destination starts before the source, and within
 *   	the range of bytes to copy [src, src + n]. In this case, the copy will
 *   	be made backwards, starting from the end (index 0 + n - 1) to the
 *   	beginning (0).
 *   2. If src < dest: The source starts before the destination, and within the
 *   	the range of bytes to copy [dest, dest + n]. In this case, the copy
 *   	will be made forwards, starting from the beginning (index 0) to the end
 *   	(index 0 + n - 1).
 *   3. Otherwise (including dest = src, i.e both buffers are one and the same)
 *   	the copy will be made forwards, as ft_memcpy would do.
 * - For every type of copy (forwards or backwards) there's a helper function
 *   to prevent the original ft_memmove from exceeding 25 lines.
 */
static void	forward_copy(unsigned char *d_ptr,
				const unsigned char *s_ptr, size_t i, size_t n)
{
	while (i < n)
	{
		*(d_ptr + i) = *(s_ptr + i);
		i++;
	}
}

static void	backward_copy(unsigned char *d_ptr,
				const unsigned char *s_ptr, size_t i, size_t n)
{
	while (i < n)
	{
		*(d_ptr + (n - 1) - i) = *(s_ptr + (n - 1) - i);
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	i = 0;
	if (dest > src && dest < src + n)
	{
		backward_copy(dest_ptr, src_ptr, i, n);
		return (dest);
	}
	else
	{
		forward_copy(dest_ptr, src_ptr, i, n);
		return (dest);
	}
}
