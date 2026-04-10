/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:19:25 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:23:34 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Additional utility functions for ft_printf

// To get and print the hex digits of pointer value (nbr)
void	putptr_hex(uintptr_t nbr, int *bytes)
{
	char	*ptr;
	int		written;
	size_t	len;

	ptr = set_hex_str_long(nbr, &len);
	get_hex_digits_long(nbr, ptr, len);
	*bytes += write(STDOUT_FILENO, "0x", 2);
	written = write(STDOUT_FILENO, ptr, len);
	if (written < 0)
	{
		*bytes = written;
		free(ptr);
		return ;
	}
	*bytes += written;
	free(ptr);
}

// To set up a new string for a hexadecimal number
char	*set_hex_str(unsigned int n, size_t *len)
{
	char	*hex_str;

	*len = ft_uintlen(n, 1);
	hex_str = (char *)malloc(*len + 1);
	if (hex_str == NULL)
		return (NULL);
	hex_str[*len] = '\0';
	return (hex_str);
}

/* To get the hexadecimal digits of a number (nbr) and fill the hex string with
   them.*/
void	get_hex_digits(unsigned int nbr, char *hex_str, size_t len)
{
	unsigned int	rem;
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
