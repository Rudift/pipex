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
	char **path_split;
	char *cmd;
	char *cmd_path;
	int	i;

	i = 0;
	cmd = ft_strjoin("/", data-> params[2]);
	path_split = ft_split(data->path, ':');
	open_infile(data);
	while (path_split[i] != NULL)
	{
		cmd_path = ft_strjoin(path_split[i] , cmd);
		if(access(cmd_path, X_OK) == 0)
		{
			if(execv(cmd_path, (char *[]){cmd_path, data->params[1], NULL}) == -1)
				perror("Error execv\n");
		}
		free (cmd_path);
		i++;
	}
	free(cmd);
	ft_freetab(path_split);
}

void	ft_cmd2(t_data *data)
{
	char **path_split;
	char *cmd;
	char *cmd_path;
	int	i;

	i = 0;
	cmd = ft_strjoin("/", data-> params[3]);
	path_split = ft_split(data->path, ':');
	open_outfile(data);
	while (path_split[i] != NULL)
	{
		cmd_path = ft_strjoin(path_split[i] , cmd);
		if(access(cmd_path, X_OK) == 0)
		{
			if(execv(cmd_path, (char *[]){cmd_path, data->params[4], NULL}) == -1)
				perror("Error execv\n");
		}
		free (cmd_path);
		i++;
	}
	free(cmd);
	ft_freetab(path_split);
}

void	forker(t_data *data)
{

	data->pid = fork();
	if (data->pid == -1)
		error_exit("Error child creation\n");
	if (data->pid != 0)
	{
		data->pid = fork();
		if (data->pid == -1)
		{
			perror("Error child creation\n");
		}
		else if (data->pid == 0)
		{
			ft_cmd2(data);
		}
	}
	else if (data->pid == 0)
	{
		ft_cmd1(data);
	}
	wait(NULL);
	wait(NULL);

}

