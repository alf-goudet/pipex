/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:22:52 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 19:24:42 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memry;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		memry = malloc(1);
		if (memry != NULL)
			return (memry);
		else
			return (NULL);
	}
	total_size = nmemb * size;
	if (total_size / size != nmemb)
		return (NULL);
	memry = malloc(total_size);
	if (memry == NULL)
		return (NULL);
	ft_bzero(memry, total_size);
	return (memry);
}
