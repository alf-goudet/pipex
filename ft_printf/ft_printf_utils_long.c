/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:59:05 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:38:44 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Helper functions for conversions of long numbers

// To set up a new string for a hexadecimal number
char	*set_hex_str_long(unsigned long n, size_t *len)
{
	char	*hex_str;

	*len = ft_ulonglen(n, 1);
	hex_str = (char *)malloc(*len + 1);
	if (hex_str == NULL)
	{
		return (NULL);
	}
	hex_str[*len] = '\0';
	return (hex_str);
}

/* To get the hexadecimal digits of a long number (nbr) and fill the hex string
    with them. */
void	get_hex_digits_long(unsigned long nbr, char *hex_str, size_t len)
{
	unsigned long	rem;
	char			dig;

	while (len > 0)
	{
		rem = nbr % 16;
		if (rem <= 9)
		{
			dig = rem + '0';
		}
		else
		{
			dig = rem + 'W';
		}
		hex_str[len - 1] = dig;
		nbr /= 16;
		len--;
	}
}
