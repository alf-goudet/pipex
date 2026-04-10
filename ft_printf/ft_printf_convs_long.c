/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:41:47 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:34:23 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Functions for conversions of long type numbers

int	handle_long_specs(va_list args, char spec)
{
	int	bytes;

	bytes = 0;
	if (spec == 'd' || spec == 'i')
		bytes = dec_int_conv_long(args, bytes);
	else if (spec == 'u')
		bytes = uint_conv_long(args, bytes);
	else if (spec == 'x' || spec == 'X')
		bytes = hex_conv_long(args, spec, bytes);
	else
	{
		write(STDERR_FILENO, "\nUnknown fd or no fd found\n", 27);
		return (-1);
	}
	return (bytes);
}

int	dec_int_conv_long(va_list args, int bytes)
{
	long	nbr;
	char	*str_form;
	size_t	len;

	nbr = va_arg(args, long);
	str_form = ft_ltoa(nbr);
	len = ft_strlen(str_form);
	bytes = write(STDOUT_FILENO, str_form, len);
	free(str_form);
	return (bytes);
}

// To print an unsigned long integer
int	uint_conv_long(va_list args, int bytes)
{
	unsigned long	nbr;
	char			*str_form;
	size_t			len;

	nbr = va_arg(args, unsigned long);
	str_form = ft_ultoa(nbr);
	len = ft_strlen(str_form);
	bytes = write(STDOUT_FILENO, str_form, len);
	free(str_form);
	return (bytes);
}

// Hex conversion of long numbers
int	hex_conv_long(va_list args, char spec, int bytes)
{
	unsigned long	nbr;
	size_t			idx;
	char			*hex_str;
	size_t			len;

	nbr = va_arg(args, unsigned long);
	hex_str = set_hex_str_long(nbr, &len);
	if (hex_str == NULL)
		return (-1);
	get_hex_digits_long(nbr, hex_str, len);
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
