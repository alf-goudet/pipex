/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:22:56 by agoudet-          #+#    #+#             */
/*   Updated: 2025/11/24 19:21:53 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_leading_whitespace(const char *str);

static int		get_sign_and_advance(const char *str, size_t *i);

static int		check_overflow(int result, int dig);

static int		check_underflow(int result, int dig);

/*
 * ft_atoi - Convert a string number to integer
 *
 * Description:
 * 	The ft_atoi function parses the string pointed to by nptr and converts
 * it to an integer number. The function will skip any leading whitespace
 * characters and manage optional signs if present (if there's only one sign
 * present before the numbers).
 *
 * Parameter:
 * 	- nptr: A constant character pointer to the number in string form to
 * convert.
 *
 * Return Value:
 * 	The function will return the integer value, including the optional
 * sign, if conversion was successful, or 0 if the given string did not contain
 * valid integer numbers.
 *
 * Notes:
 * 	A valid C string for ft_atoi is one that contains integer numbers not
 * preceded by non-digit characters (except for leading whitespaces, which will
 * be skipped altogether, and one optional sign, which can be used as the final
 * integer's sign).
 *
 * To handle leading whitespace and optional number signs, two helper functions
 * were defined: skip_leading_whitespace() and get_sign_and_advance().
 *
 * After skipping leading whitespace and handling the optional sign, ft_atoi
 * checks if the current character is a digit through the ft_isdigit function,
 * and if it is, it will:
 * 1. Get the current digit in integer form by subtracting the ASCII value of
 * '0' from its own.
 * 2. It accumulates the digit in a variable that will hold the final result to
 * return. It does so by multiplying the current result value by 10 and then
 * adding the obtained digit.
 * 3. Keeps going for every successive digit until hitting a non-digit.
 *
 * The function also handles NULL pointers by returning 0 before doing anything
 * else. It also handles integer overflow and underflow through two dedicated
 * helper functions: check_overflow and check_underflow. This way, the function
 * ft_atoi gets to clamp the results to the [INT_MIN..INT_MAX] ranges.
 */
int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	int			result;
	int			digit;

	if (nptr == NULL)
		return (0);
	i = skip_leading_whitespace(nptr);
	sign = get_sign_and_advance(nptr, &i);
	result = 0;
	while (ft_isdigit(nptr[i]))
	{
		digit = nptr[i] - '0';
		if (sign == 1 && check_overflow(result, digit))
			return (INT_MAX);
		else if (check_underflow(result, digit))
			return (INT_MIN);
		result = result * 10 + digit;
		i++;
	}
	return (sign * result);
}

/*
 * skip_leading_whitespace - Skip all leading whitespace characters
 *
 * Description:
 * 	This helper function for ft_atoi will detect any whitespace characters
 * present as the first characters of the given string and increments the index
 * until the next element is non-whitespace (including '\0').
 *
 * Parameter:
 * 	*str: A constant character pointer to the string passed from ft_atoi.
 *
 * Return value:
 * 	The helper function returns the string index of the first
 * non-whitespace character, or if all string characters are whitespace, the
 * index of the null terminator '\0'.
 */
static size_t	skip_leading_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r')
		i++;
	return (i);
}

/*
 * get_sign_and_advance - Get the optional sign for integer conversion
 *
 * Description:
 * 	This helper function examines the character at the current index, and
 * if it is a sign, it will capture that sign for use in the ft_atoi conversion
 * to integer, and move the index of that sign to the next position.
 *
 * Parameters:
 * 	- *str: A constant character pointer to the string passed from ft_atoi.
 * 	- *index: A size_t pointer to the index's current position as it was
 * when ft_atoi called the helper function (after skipping whitespace).
 *
 * Return value:
 * 	The helper function returns -1 if the captured sign was '-', or 1 if it
 * was '+'.
 *
 * Notes:
 * 	This function only considers one optional sign (the first) before an
 * integer number in the string. If the string has more than one sign following
 * an integer number (Ex: "+-++20") the function will only get the leftmost
 * sign, and since there are more signs before the integer number, ft_atoi will
 * consider the string invalid for conversion and return 0.
 */
static int	get_sign_and_advance(const char *str, size_t *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '-')
	{
		sign = -1;
		(*index)++;
	}
	else if (str[*index] == '+')
	{
		sign = 1;
		(*index)++;
	}
	return (sign);
}

static int	check_overflow(int result, int dig)
{
	if (result > INT_MAX / 10)
		return (1);
	else if (result == INT_MAX / 10 && dig > INT_MAX % 10)
		return (1);
	else
		return (0);
}

static int	check_underflow(int result, int dig)
{
	if (result > INT_MAX / 10)
		return (1);
	else if (result == INT_MAX / 10 && dig > (INT_MAX % 10) + 1)
		return (1);
	else
		return (0);
}
