/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-21 09:04:21 by vdeliere          #+#    #+#             */
/*   Updated: 2025-02-21 09:04:21 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <time.h>
# include "../libft/libft.h"
# include <errno.h>

typedef struct s_data
{
	char	**params;
	char	*path;
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	pid_t	pid;
}	t_data;

/*Main*/
void	error_exit(char *str, t_data *data);
void	perror_exit(char *str, t_data *data);

/*Pipex*/
void	pipex(t_data *data);

/*Process*/
void	forker(t_data *data);
void	process_infile(t_data *data);
void	process_outfile(t_data *data);
void	ft_cmd1(t_data *data);
void	ft_cmd2(t_data *data);

/*Files*/
void	open_infile(t_data	*data);
void	open_outfile(t_data *data);

#endif