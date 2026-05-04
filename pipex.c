/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:27:45 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/04 19:55:34 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	get_pipex_name(char **argv)
{
	char	*pipex_name;
	size_t	name_len;

	name_len = ft_strlen(argv[0]);
	pipex_name = ft_strnstr(argv[0], "pipex", name_len);
	argv[0] = pipex_name;
}

static void	handle_no_infile_error(char **argv)
{
	char	*pipex_name;
	char	*error_msg;
	char	*infile;
	int		lower_char;
	int		ft_printf_fd;

	pipex_name = argv[0];
	error_msg = ft_strdup(strerror(errno));
	lower_char = ft_tolower((int)error_msg[0]);
	error_msg[0] = (char)lower_char;
	infile = argv[1];
	ft_printf_fd = dup2(STDERR_FILENO, STDOUT_FILENO);
	check_proc_error("dup2()", ft_printf_fd);
	ft_printf("%s: %s: %s\n", pipex_name, error_msg, infile);
	free(error_msg);
	exit(EXIT_FAILURE);
}

static void	check_infile_availability(char **argv, char **envp)
{
	char	*pwd;
	char	*infile;
	char	*infile_path;
	int		availability_check;

	pwd = ft_getenv_p("PWD", envp);
	pwd = ft_strjoin(pwd, "/");
	infile = argv[1];
	infile_path = ft_strjoin(pwd, infile);
	free(pwd);
	availability_check = access(infile_path, F_OK | R_OK);
	if (availability_check == -1)
	{
		free(infile_path);
		handle_no_infile_error(argv);
	}
	free(infile_path);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd1;
	t_cmd	cmd2;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	get_pipex_name(argv);
	check_infile_availability(argv, envp);
	ft_bzero(&cmd1, sizeof(t_cmd));
	cmd1.nbr = 1;
	cmd1.targ_file = argv[1];
	cmd1.redirect_put = &redirect_input;
	get_program(&cmd1, argv[2], envp);
	ft_bzero(&cmd2, sizeof(t_cmd));
	cmd2.targ_file = argv[4];
	cmd2.nbr = 2;
	cmd2.redirect_put = &redirect_output;
	get_program(&cmd2, argv[3], envp);
	exit(EXIT_SUCCESS);
}
