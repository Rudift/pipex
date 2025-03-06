/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-27 12:36:37 by vdeliere          #+#    #+#             */
/*   Updated: 2025-02-27 12:36:37 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Gestion des processus (fork, execve)

void	ft_cmd1(t_data *data)
{
	char	**path_split;
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd = NULL;
	path_split = NULL;
	cmd = ft_split(data->params[2], ' ');
	path_split = ft_split(data->path, ':');
	while (path_split[i] != NULL)
	{
		cmd_path = ft_strjoin(path_split[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			if (execv(cmd_path, (char *[]){cmd_path, cmd[1], NULL}) == -1)
				perror("Error execv\n");
			break ;
		}
		free (cmd_path);
		i++;
	}
	if (path_split[i] == NULL)
		perror("command not found : cmd1\n");
	free(cmd);
	if (path_split)
		ft_freetab(path_split);
	exit(127);
}

void	ft_cmd2(t_data *data)
{
	char	**path_split;
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd = ft_split(data->params[3], ' ');
	path_split = ft_split(data->path, ':');
	while (path_split[i] != NULL)
	{
		cmd_path = ft_strjoin(path_split[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			if (execv(cmd_path, (char *[]){cmd_path, cmd[1], NULL}) == -1)
				perror("Error execv\n");
			break ;
		}
		free (cmd_path);
		i++;
	}
	if (path_split[i] == NULL)
		perror("command not found : cmd2\n");
	free(cmd);
	ft_freetab(path_split);
	exit(127);
}

void	forker(t_data *data)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		close(data->pipe_fd[0]);
		open_infile(data);
		dup2(data->infile, 0);
		close(data->infile);
		dup2(data->pipe_fd[1], 1);
		close (data->pipe_fd[1]);
		ft_cmd1(data);
	}
	data->pid = fork();
	if (data->pid == 0)
	{
		close (data->pipe_fd[1]);
		open_outfile(data);
		dup2(data->outfile, 1);
		close(data->outfile);
		dup2(data->pipe_fd[0], 0);
		close(data->pipe_fd[0]);
		ft_cmd2(data);
	}
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}
