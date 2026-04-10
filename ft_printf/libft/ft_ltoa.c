/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:18:51 by agoudet-          #+#    #+#             */
/*   Updated: 2026/02/04 17:33:08 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ltoa_min(void);

static void	set_len_and_sign(long *n, int *len, int *is_neg);

char	*ft_ltoa(long n)
{
	char	*str;
	int		len;
	int		is_neg;
	char	dig;

	if (n == LONG_MIN)
		return (ft_ltoa_min());
	set_len_and_sign(&n, &len, &is_neg);
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
	if (is_neg)
		str[0] = '-';
	return (str);
}

static char	*ft_ltoa_min(void)
{
	char			*min_str;
	const size_t	len = 20;

	min_str = (char *)malloc(len + 1);
	if (min_str == NULL)
		return (NULL);
	ft_strlcpy(min_str, "-9223372036854775808", len + 1);
	return (min_str);
}

static void	set_len_and_sign(long *n, int *len, int *is_neg)
{
	long	temp;

	*len = 0;
	*is_neg = 0;
	if (*n < 0)
	{
		*is_neg = 1;
		(*len)++;
		*n = -(*n);
	}
	else if (*n == 0)
		*len = 1;
	temp = *n;
	while (temp != 0)
	{
		temp /= 10;
		(*len)++;
	}
}
