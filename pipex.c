/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:27:45 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/30 19:38:54 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_msg_and_abort(void)
{
	ft_printf("Please enter a command to run\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd1;
	char	*cmd2;

	if (argc == 1)
		print_msg_and_abort();
	cmd1 = argv[1];
	get_program(cmd1, envp);
	if (argc == 3)
	{
		cmd2 = argv[2];
		get_program(cmd2, envp);
	}
	exit(EXIT_SUCCESS);
}
