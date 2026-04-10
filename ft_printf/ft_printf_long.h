/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_long.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:04:26 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:43:23 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Subheader file containing modified conversions and helper functions
   for numbers of type long (conversions with 'l' length modifier). */

#ifndef FT_PRINTF_LONG_H
# define FT_PRINTF_LONG_H
# include <unistd.h> // for write()
# include <stdlib.h> // for malloc() and free()
# include <stdarg.h> // for va_list type and va_*() macros

// Core function for handling long number conversions
int		handle_long_specs(va_list args, char spec);

// Conversion specifier functions
int		dec_int_conv_long(va_list args, int bytes);			// %ld or %li
int		uint_conv_long(va_list args, int bytes);			// %lu
int		hex_conv_long(va_list args, char spec, int bytes);	// %lx or %lX

// Utility functions
char	*set_hex_str_long(unsigned long n, size_t *len);
void	get_hex_digits_long(unsigned long nbr, char *hex_str, size_t len);
#endif