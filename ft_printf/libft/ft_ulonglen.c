/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:45:57 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:40:49 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_ulonglen - Get number of digits of an unsigned long number
 * 
 * If need_hex == 1, then the function will calculate the number of digits of
 * the number n in hexadecimal format.
 */
size_t	ft_ulonglen(unsigned long n, int const need_hex)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		if (need_hex)
			n /= 16;
		else
			n /= 10;
		len++;
	}
	return (len);
}
