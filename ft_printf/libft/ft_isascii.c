/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:07:46 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:51:09 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Brief: ft_isascii() takes an int c and verifies if the value
 * represents a 7-bit unsigned char that fits within the range of standard
 * ASCII values (0 to 127). If so, it returns 1, else 0.
 *
 * NOTE: The function will not consider extended ASCII values (128-255) as
 * they go beyond the original isascii() function's 7-bit limit into 8-bit
 * unsigned chars ([2**7=128 - 2**8=256]).
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
