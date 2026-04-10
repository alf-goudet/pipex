/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:32:18 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:55:00 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function takes an integer c and returns 1 if it represents a printable
 * character (the space character ' ' is included), or 0 if not.
 *
 * NOTE: The function does not consider extended ASCII characters.
 * 
 * Printable chars are those whose ASCII integer value is between 32 and 126,
 * both included.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
