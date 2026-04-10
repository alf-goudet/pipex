/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:36:52 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:07:43 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Description:
 * 	Compares the first n bytes of two strings s1 and s2.
 * Parameters:
 * 	s1 and s2: The two strings to compare with each other (const char *).
 * 	n: The max number of bytes to compare (size_t).
 * Return Value (One of three possible cases of integers)
 * 	- 0: If the first n bytes of s1 and s2 were found to be equal.
 * 	- Less than 0: If the first n bytes of s1 were found to be less than
 * 	those of s2.
 * 	- Greater than 0: If the first n bytes of s1 were found to be greater than
 *      those of s2.
 * The comparison is made using unsigned characters.
 *
 * Detailed logic:
 *	The function iterates through the strings one char at a time, up to n bytes
 *	(could be less than n bytes). Iteration will stop whenever a) a difference
 *	is spotted between the two strings, b) a null terminator was detected in
 *	s1, or c) the byte limit n was reached. After the loop, the return value is
 *	determined by the characters in s1 and s2 at the index i where the loop
 *	stopped (calculated by s1[i] - s2[i]) or if the loop ended because n bytes
 *	were compared with not a difference found.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
