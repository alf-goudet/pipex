/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:09:37 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 23:41:55 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	len;
	char	dig;

	len = ft_uintlen(n, 0);
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
