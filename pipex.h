/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:30:12 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/04 21:28:28 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h" 	// to use my ft_printf()
# include "ft_printf/libft/libft.h" // to use my libft functions
# include <sys/types.h>				// for pid_t
# include <sys/wait.h>				// for wait() and waitpid()
# include <fcntl.h> 				// for open() and close()
# include <stdio.h> 				// for perror()
# include <string.h>				// for strerror()
# include <unistd.h>				// for dup2(), fork() and execve()
# include <stdlib.h>				// for exit()
# include <errno.h>					// for handling error messages with errno

// Defined structure for command metadata
typedef struct s_cmd
{
	char	*name;
	int		nbr;
	char	*exec_path;
	char	**argv;
	char	*targ_file;
	void	(*redirect_put)(char *);
}			t_cmd;

char	*get_cmd_path(char **envp, char *cmd);
void	free_double_ptr(char **ptr);
void	get_program(t_cmd *cmd, char *cmd_arg, char **envp);
void	redirect_output(char *file_name);
void	redirect_input(char *file_name);

// Error checkers (at error_handle.c)
void	check_proc_error(char *proc, const int value);
void	check_ptr_error(char *func, char *ptr);
void	check_double_ptr_error(char *func, char **ptr);

#endif
