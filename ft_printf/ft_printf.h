/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:12:34 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/06 19:55:11 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h" // to use libft functions
# include "ft_printf_long.h" // functions for long number conversions
# include <stdlib.h> // for malloc() and free()
# include <unistd.h> // for write()
# include <stdarg.h> // to make ft_printf() variadic
# include <stdint.h> // for int precision typedefs (for portability)

int		ft_printf(const char *format, ...);

// Conversion specifier functions
int		char_str_conv(va_list args, char spec, int bytes);
int		ptr_conv(va_list args, int bytes);
int		dec_int_conv(va_list args, int bytes);
int		uint_conv(va_list args, int bytes);
int		hex_conv(va_list args, char spec, int bytes);

// Utility functions for ft_printf (outside libft)
void	putptr_hex(uintptr_t nbr, int *bytes);
void	get_hex_digits(unsigned int nbr, char *hex_str, size_t len);
char	*set_hex_str(unsigned int n, size_t *len);

#endif
