/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:46:09 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:28:58 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Functions dedicated to handling of ft_printf format conversions

// To handle character or string conversions
int	char_str_conv(va_list args, char spec, int bytes)
{
	unsigned char	chr;
	const char		*str;
	size_t			len;

	if (spec == 'c')
	{
		str = NULL;
		len = 1;
		chr = (unsigned char)va_arg(args, int);
		bytes = write(STDOUT_FILENO, &chr, len);
	}
	else
	{
		chr = '\0';
		str = va_arg(args, const char *);
		if (str == NULL)
		{
			bytes = write(STDOUT_FILENO, "(null)", 6);
			return (bytes);
		}
		len = ft_strlen(str);
		bytes = write(STDOUT_FILENO, str, len);
	}
	return (bytes);
}

// To print a memory address (pointer value) in hex format 
int	ptr_conv(va_list args, int bytes)
{
	uintptr_t	ptr_int;

	ptr_int = (uintptr_t)va_arg(args, void *);
	if (ptr_int == 0)
	{
		bytes = write(STDOUT_FILENO, "(nil)", 5);
		return (bytes);
	}
	putptr_hex(ptr_int, &bytes);
	return (bytes);
}

// To print a signed integer in decimal format
// (%d and %i work exactly the same here)
int	dec_int_conv(va_list args, int bytes)
{
	int		nbr;
	char	*str_form;
	size_t	len;

	nbr = va_arg(args, int);
	str_form = ft_itoa(nbr);
	len = ft_strlen(str_form);
	bytes = write(STDOUT_FILENO, str_form, len);
	free(str_form);
	return (bytes);
}

// To print an unsigned integer
int	uint_conv(va_list args, int bytes)
{
	unsigned int	nbr;
	char			*str_form;
	size_t			len;

	nbr = va_arg(args, unsigned int);
	str_form = ft_uitoa(nbr);
	len = ft_strlen(str_form);
	bytes = write(STDOUT_FILENO, str_form, len);
	free(str_form);
	return (bytes);
}

// To print a number in lowercase hexadecimal (converting to uppercase
// if requested via %X)
int	hex_conv(va_list args, char spec, int bytes)
{
	unsigned int	nbr;
	unsigned int	idx;
	char			*hex_str;
	size_t			len;

	nbr = va_arg(args, unsigned int);
	hex_str = set_hex_str(nbr, &len);
	if (hex_str == NULL)
		return (-1);
	get_hex_digits(nbr, hex_str, len);
	if (spec == 'X')
	{
		idx = 0;
		while (hex_str[idx] != '\0')
		{
			hex_str[idx] = ft_toupper(hex_str[idx]);
			idx++;
		}
	}
	len = ft_strlen(hex_str);
	bytes = write(STDOUT_FILENO, hex_str, len);
	free(hex_str);
	return (bytes);
}
