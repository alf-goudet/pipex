/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:22:37 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:57:16 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*byte_ptr1;
	const unsigned char	*byte_ptr2;

	if (n == 0)
		return (0);
	byte_ptr1 = (const unsigned char *)s1;
	byte_ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (byte_ptr1[i] != byte_ptr2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	else
		return (byte_ptr1[i] - byte_ptr2[i]);
}
