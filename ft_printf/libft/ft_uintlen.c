/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:03 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:40:36 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_uintlen - Get number of digits of an unsigned integer number
 * 
 * If need_hex == 1, then the function will calculate the number of digits of
 * the number n in hexadecimal format.
 */
size_t	ft_uintlen(unsigned int n, int const need_hex)
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
