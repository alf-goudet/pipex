/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:30:58 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/29 13:49:07 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*parse_path(char **paths, char *cmd)
{
	char	*exec_path;
	int		access_check;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		ft_strlcat(paths[i], "/", ft_strlen(paths[i]) + 2);
		exec_path = ft_strjoin(paths[i], cmd);
		check_ptr("ft_strjoin()", exec_path);
		access_check = access(exec_path, F_OK | X_OK);
		if (access_check == -1)
			free(exec_path);
		else
		{
			free_double_ptr(paths);
			return (exec_path);
		}
		i++;
	}
	free_double_ptr(paths);
	return (NULL);
}

char	*get_cmd_path(char **envp, char *cmd)
{
	char		*path_env;
	char		**paths;
	char		*prog_path;

	path_env = ft_getenv_p("PATH", envp);
	paths = ft_split(path_env, ':');
	check_double_ptr("PATH splitting failure", paths);
	prog_path = parse_path(paths, cmd);
	return (prog_path);
}
