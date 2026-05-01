/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:30:58 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/30 19:19:41 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*parse_path(char **paths, char *cmd)
{
	char	*exec_path;
	char	*pre_exec_path;
	int		access_check;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		pre_exec_path = ft_strjoin(paths[i], "/");
		check_ptr_error("ft_strjoin()", pre_exec_path);
		exec_path = ft_strjoin(pre_exec_path, cmd);
		free(pre_exec_path);
		check_ptr_error("ft_strjoin()", exec_path);
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
	check_double_ptr_error("PATH splitting failure", paths);
	prog_path = parse_path(paths, cmd);
	return (prog_path);
}
