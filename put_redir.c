/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:07:55 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/04 21:24:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_input(char *file_name)
{
	int	input_fd;
	int	old_fd;

	old_fd = open(file_name, O_RDONLY, 00744);
	check_proc_error("open()", (const int)old_fd);
	close(STDIN_FILENO);
	input_fd = dup(old_fd);
	check_proc_error("dup()", (const int)input_fd);
	close(old_fd);
}

void	redirect_output(char *file_name)
{
	int	output_fd;
	int	old_fd;

	old_fd = open(file_name, O_CREAT | O_WRONLY, 00722);
	check_proc_error("open()", (const int)old_fd);
	close(STDOUT_FILENO);
	output_fd = dup(old_fd);
	check_proc_error("dup()", (const int)output_fd);
	close(old_fd);
}
