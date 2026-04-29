/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:50:08 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/29 13:38:39 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_getenv_p - Get an environment variable from an environment pointer
char	*ft_getenv_p(const char *name, char **envp)
{
	char	*path_env;
	size_t	len;
	size_t	i;

	len = ft_strlen(name) + 1;
	i = 1;
	path_env = ft_strnstr(envp[i], name, len);
	while (path_env == NULL)
	{
		i++;	
		path_env = ft_strnstr(envp[i], name, len);
	}
	path_env += len;
	return (path_env);
}
