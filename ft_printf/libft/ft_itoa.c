/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 22:18:51 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 21:55:44 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_min(void);

static void	set_len_and_sign(int n, long *nb, int *len, int *is_neg);

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;
	int		is_neg;
	char	dig;

	if (n == INT_MIN)
		return (ft_itoa_min());
	nb = n;
	set_len_and_sign(n, &nb, &len, &is_neg);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		dig = (nb % 10) + '0';
		nb /= 10;
		str[len - 1] = dig;
		len--;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}

static char	*ft_itoa_min(void)
{
	char			*min_str;
	const size_t	len = 11;

	min_str = (char *)malloc(len + 1);
	if (min_str == NULL)
		return (NULL);
	ft_strlcpy(min_str, "-2147483648", len + 1);
	return (min_str);
}

static void	set_len_and_sign(int n, long *nb, int *len, int *is_neg)
{
	long	temp;

	*len = 0;
	*is_neg = 0;
	if (n < 0)
	{
		*is_neg = 1;
		(*len)++;
		*nb = -(*nb);
	}
	else if (n == 0)
		*len = 1;
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		(*len)++;
	}
}
