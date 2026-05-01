/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_runner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:23:37 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/30 20:32:20 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parse_cmd_argv(char **cmd_argv, char **envp);

static char	*replace_with_home(char *path, char **envp);

static void	run_program(char *prog_path, char **cmd_argv, char **envp);

void	get_program(char *cmd_arg, char **envp)
{
	char	**cmd_argv;
	char	*prog_path;

	cmd_argv = ft_split(cmd_arg, ' ');
	check_double_ptr_error("ft_split()", cmd_argv);
	parse_cmd_argv(cmd_argv, envp);
	prog_path = get_cmd_path(envp, *cmd_argv);
	check_ptr_error("Command not found", prog_path);
	run_program(prog_path, cmd_argv, envp);
}

static void	parse_cmd_argv(char **cmd_argv, char **envp)
{
	int	i;

	i = 0;
	while (cmd_argv[i] != NULL)
	{
		if (cmd_argv[i][0] == '~')
			cmd_argv[i] = replace_with_home(cmd_argv[i], envp);
		i++;
	}
}

static char	*replace_with_home(char *path, char **envp)
{
	char	*home_path;
	char	*old_path;
	char	*sub_path;
	int		no_sub_path;
	size_t	sub_path_len;

	home_path = ft_getenv_p("HOME", envp);
	old_path = path;
	no_sub_path = *(path + 1) == '\0';
	if (no_sub_path)
		path = ft_strdup(home_path);
	else
	{
		sub_path_len = ft_strlen(path) - 1;
		sub_path = ft_substr(path, 1, sub_path_len);
		path = ft_strjoin(home_path, sub_path);
		free(sub_path);
	}
	check_ptr_error("ft_strdup()", path);
	free(old_path);
	return (path);
}

static void	run_program(char *prog_path, char **cmd_argv, char **envp)
{
	pid_t	pid;
	int		exec_check;

	pid = fork();
	check_proc_error("fork()", (int)pid);
	if (pid == 0)
	{
		exec_check = execve(prog_path, cmd_argv, envp);
		check_proc_error("execve()", exec_check);
	}
	else
	{
		pid = wait(NULL);
		check_proc_error("wait()", (int)pid);
		free(prog_path);
		free_double_ptr(cmd_argv);
	}
}
