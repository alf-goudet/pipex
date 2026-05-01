/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:30:12 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/30 16:47:27 by agoudet-         ###   ########.fr       */
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
# include <unistd.h>				// for dup2(), fork() and execve()
# include <stdlib.h>				// for exit()

char	*get_cmd_path(char **envp, char *cmd);
void	free_double_ptr(char **ptr);
void	get_program(char *cmd_arg, char **envp);

// Error checkers (at error_handle.c)
void	check_proc_error(char *proc, const int value);
void	check_ptr_error(char *func, char *ptr);
void	check_double_ptr_error(char *func, char **ptr);

#endif
