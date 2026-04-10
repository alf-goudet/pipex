/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:26:30 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:05:18 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Brief: ft_strlcat appends (concatenates) a source string to the end of a
 * destination string, up to a given buffer size.
 *
 * Parameters:
 * - dst: A char pointer to the destination string to append to the end of.
 * - src: A constant char pointer to the source string to take from for
 *   concatenation.
 * - size: The size of the buffer to concatenate at. It must include a space
 *   for the NULL terminator '\0'.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_i;
	size_t	src_i;
	size_t	initial_dst_len;
	size_t	final_dst_len;

	dst_i = 0;
	while (dst[dst_i] != '\0' && dst_i < size)
		dst_i++;
	initial_dst_len = dst_i;
	final_dst_len = initial_dst_len + ft_strlen(src);
	if (size == 0 || dst_i >= size)
		return (final_dst_len);
	src_i = 0;
	while (src[src_i] != '\0' && dst_i < size - 1)
	{
		dst[dst_i] = src[src_i];
		dst_i++;
		src_i++;
	}
	if (dst_i < size)
		dst[dst_i] = '\0';
	return (final_dst_len);
}
