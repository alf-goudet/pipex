/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:22:17 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:08:49 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strnstr - Find a substring in a string
 *
 * Description:
 * The ft_strnstr() function is a replicated version of the standard strnstr()
 * function, whose goal is to search for a substring little within a larger
 * string big, limiting the search to the first len characters of big.
 *
 * Parameters:
 * - big: A pointer to the string to search. It is constant because it isn't
 *   meant to be modified.
 * - little: A pointer to the substring to locate within big. It must be a
 *   C string (meaning it's null-terminated) and it's also a constant like big.
 * - len: A size_t limit of characters to search from the start of big.
 *
 * Return Value:
 * Depending on the scenario, the function will return different values:
 * - If little is an empty string, it will return a pointer to the first
 *   element of big.
 * - If little is found inside big, it returns a pointer to the position in big
 *   where the match with little begins.
 * - If little is nowhere to be found within the first len characters of big,
 *   it returns NULL. This occurs either if the search within len characters is
 *   complete and unsuccessful, or if len is less than the calculated length of
 *   little (little_len), as the substring won't have the enough length to be
 *   whole without crossing len characters.
 *
 *   The return type is a non-constant character pointer.
 * 
 * Behavior Notes:
 * This function handles null terminators within a string. It does so by
 * ending the search whenever a '\0' is spotted in big.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (little[0] == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	if (len < little_len)
		return (NULL);
	i = 0;
	while (i <= len - little_len && big[i] != '\0')
	{
		j = 0;
		while (j < little_len && little[j] == big[i + j])
			j++;
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
