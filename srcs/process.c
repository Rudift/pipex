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

void	ft_cmd1_inette(t_data *data, char **path_split, char **cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	while (path_split[i] != NULL)
	{
		tmp = ft_strjoin(path_split[i], "/");
		cmd_path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
		{
			if (execv(cmd_path, (char *[]){cmd_path, cmd[1], NULL}) == -1)
				perror("Error execv");
			break ;
		}
		free (cmd_path);
		i++;
	}
	ft_freetab(cmd);
	if (path_split[i] == NULL)
		perror("command not found");
}

void	ft_cmd1(t_data *data)
{
	char	**path_split;
	char	**cmd;

	cmd = NULL;
	path_split = NULL;
	cmd = ft_split(data->params[2], ' ');
	path_split = ft_split(data->path, ':');
	ft_cmd1_inette(data, path_split, cmd);
	if (path_split)
		ft_freetab(path_split);
	free(data);
	exit(127);
}

void	ft_cmd2_inette(t_data *data, char **path_split, char **cmd)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	while (path_split[i] != NULL)
	{
		tmp = ft_strjoin(path_split[i], "/");
		cmd_path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
		{
			if (execv(cmd_path, (char *[]){cmd_path, cmd[1], NULL}) == -1)
				perror("Error execv");
			break ;
		}
		free (cmd_path);
		i++;
	}
	ft_freetab(cmd);
	if (path_split[i] == NULL)
		perror("command not found");
}

void	ft_cmd2(t_data *data)
{
	char	**path_split;
	char	**cmd;

	cmd = ft_split(data->params[3], ' ');
	path_split = ft_split(data->path, ':');
	ft_cmd2_inette(data, path_split, cmd);
	ft_freetab(path_split);
	free(data);
	exit(127);
}

void	forker(t_data *data)
{
	data->pid = fork();
	if (data->pid == 0)
		process_infile(data);
	data->pid = fork();
	if (data->pid == 0)
		process_outfile(data);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}
