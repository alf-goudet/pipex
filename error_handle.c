/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:11:01 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/30 16:57:46 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	handle_error(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

void	check_proc_error(char *proc, const int value)
{
	if (value == -1)
	{
		handle_error(proc);
	}
}

void	check_ptr_error(char *func, char *ptr)
{
	if (ptr == NULL)
	{
		handle_error(func);
	}
}

void	check_double_ptr_error(char *func, char **ptr)
{
	if (ptr == NULL)
	{
		handle_error(func);
	}
}
