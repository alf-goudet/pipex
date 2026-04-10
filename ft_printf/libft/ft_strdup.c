/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 19:10:51 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 22:02:31 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strdup - Duplicate a string
 *
 * Description:
 * 	The ft_strdup() function creates a new string that is a duplicate of a
 * given string s.
 *
 * Parameter:
 * 	- s: A constant character pointer to the string to duplicate. It is
 * constant to unsure non-modification during the duping process.
 *
 * Return Value:
 * 	On success, ft_strdup() returns a pointer to the new duplicated string.
 * On failure, usually due to insufficient space in memory for the dupe, it
 * will return NULL.
 *
 * Other Notes:
 * 	- This function allocates memory for the duplicate by using malloc().
 * It is the responsibility of the user of this function to ensure the memory
 * is properly freed at the end.
 * 	- The returned pointer (if not NULL) must be freed using free() when no
 * longer needed. This will prevent memory leaks.
 * 	- The copying of the string s to its duplicate will be done using
 * ft_memcpy().
 * 	- The necessary inclusions for this function inside "libft.h":
 * <stddef.h> for size_t type declaration (for string length) and <stdlib.h> for
 * malloc().
 */
char	*ft_strdup(const char *s)
{
	char		*s_dup;
	size_t		len;

	len = ft_strlen(s);
	s_dup = (char *)malloc(len + 1);
	if (s_dup == NULL)
		return (NULL);
	ft_memcpy(s_dup, s, len + 1);
	return (s_dup);
}
