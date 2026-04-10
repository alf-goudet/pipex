/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:04:47 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/03 16:30:57 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_and_write(va_list args, const char *format, size_t len);

static int	handle_format(va_list args, const char *format, size_t *idx);

static int	handle_type_length(va_list args, const char *format, size_t *idx);

static int	handle_specifier(va_list args, char spec);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	length;
	int		bytes_written;

	if (format == NULL)
		return (-1);
	length = ft_strlen(format);
	if (ft_strchr(format, '%') == NULL)
	{
		bytes_written = write(STDOUT_FILENO, format, length);
		return (bytes_written);
	}
	va_start(args, format);
	bytes_written = parse_and_write(args, format, length);
	va_end(args);
	return (bytes_written);
}

static int	parse_and_write(va_list args, const char *format, size_t len)
{
	size_t	idx;
	size_t	start;
	size_t	byte_count;

	byte_count = 0;
	idx = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%')
		{
			byte_count += handle_format(args, format, &idx);
			idx++;
		}
		else
		{
			start = idx;
			while (format[idx] != '%' && format[idx] != '\0')
				idx++;
			len = idx - start;
			byte_count += write(STDOUT_FILENO, &format[start], len);
		}
	}
	return (byte_count);
}

static int	handle_format(va_list args, const char *format, size_t *idx)
{
	int		bytes;
	char	spec;

	(*idx)++;
	if (format[*idx] == 'l')
		bytes = handle_type_length(args, format, idx);
	else
	{
		spec = format[*idx];
		bytes = handle_specifier(args, spec);
	}
	return (bytes);
}

static int	handle_type_length(va_list args, const char *format, size_t *idx)
{
	int		bytes;
	char	spec;

	bytes = 0;
	if (format[*idx] == 'l')
	{
		(*idx)++;
		spec = format[*idx];
		bytes = handle_long_specs(args, spec);
	}
	return (bytes);
}

static int	handle_specifier(va_list args, char spec)
{
	int	bytes;

	bytes = 0;
	if (spec == 'c' || spec == 's')
		bytes = char_str_conv(args, spec, bytes);
	else if (spec == 'p')
		bytes = ptr_conv(args, bytes);
	else if (spec == 'd' || spec == 'i')
		bytes = dec_int_conv(args, bytes);
	else if (spec == 'u')
		bytes = uint_conv(args, bytes);
	else if (spec == 'x' || spec == 'X')
		bytes = hex_conv(args, spec, bytes);
	else if (spec == '%')
		bytes = write(STDOUT_FILENO, "%", 1);
	else
	{
		write(STDERR_FILENO, "\nUnknown fd or no fd found\n", 27);
		return (-1);
	}
	return (bytes);
}
