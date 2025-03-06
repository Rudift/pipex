/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-06 15:33:54 by vdeliere          #+#    #+#             */
/*   Updated: 2025-03-06 15:33:54 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_infile(t_data *data)
{
	close(data->pipe_fd[0]);
	open_infile(data);
	dup2(data->infile, 0);
	close(data->infile);
	dup2(data->pipe_fd[1], 1);
	close (data->pipe_fd[1]);
	ft_cmd1(data);
}

void	process_outfile(t_data *data)
{
	close (data->pipe_fd[1]);
	open_outfile(data);
	dup2(data->outfile, 1);
	close(data->outfile);
	dup2(data->pipe_fd[0], 0);
	close(data->pipe_fd[0]);
	ft_cmd2(data);
}
