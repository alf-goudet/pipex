/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_runner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:23:37 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/29 13:55:47 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_cmd_argc(char **split_argv)
{
	int	i;

	i = 1;
	while (split_argv[i] != NULL)
		i++;
	return (i);
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
		free_double_ptr(cmd_argv);
	}
}

void	get_program(int argc, char **argv, char **envp)
{
	char	**cmd_argv;
	char	**split_argv;
	char	*prog_path;
	int		cmd_argc;
	int		i;

	split_argv = ft_split(argv[1], ' ');
	check_double_ptr("ft_split()", split_argv);
	cmd_argc = get_cmd_argc(split_argv);
	cmd_argv = (char **)malloc((argc + cmd_argc) * sizeof(char *));
	check_double_ptr("malloc()", cmd_argv);
	prog_path = get_cmd_path(envp, *split_argv);
	check_ptr("Command not found", prog_path);
	free(*split_argv);
	cmd_argv[0] = prog_path;
	i = 1;
	while (i < cmd_argc)
	{
		cmd_argv[i] = split_argv[i];
		i++;
	}
	free(split_argv);
	run_program(prog_path, cmd_argv, envp);
}
