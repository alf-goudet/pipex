/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:09:12 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:40:13 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(unsigned long n)
{
	char	*str;
	size_t	len;
	char	dig;

	len = ft_ulonglen(n, 0);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		dig = (n % 10) + '0';
		n /= 10;
		str[len - 1] = dig;
		len--;
	}
	return (str);
}
