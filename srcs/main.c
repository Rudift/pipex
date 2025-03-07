/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-21 09:02:48 by vdeliere          #+#    #+#             */
/*   Updated: 2025-02-21 09:02:48 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Appel de pipex et gestion d'erreurs

void	error_exit(char *str, t_data *data)
{
	perror(str);
	if (data)
	{
		// if (data->path)
		// {
		// 	free (data->path);
		// 	data->path = NULL;
		// }
		free(data);
		data = NULL;
	}
	exit(EXIT_FAILURE);
}

void	ft_getenv(char **envp, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (envp == NULL)
		error_exit("command not found getenv", data);
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] != NULL)
	{
		while (envp[i][j] != '=')
			j++;
		j++;
		data->path = &envp[i][j];
	}
	else
		error_exit ("Path error", data);
}

void	data_init(t_data *data, char **av, char **envp)
{
	data->params = av;
	data->path = NULL;
	ft_getenv(envp, data);
	data->pipe_fd[0] = 0;
	data->pipe_fd[1] = 0;
	data->infile = 0;
	data->outfile = 0;
	data->pid = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	data = NULL;
	if (ac != 5)
		error_exit("parse error", data);
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	data_init(data, av, envp);
	pipex(data);
	forker(data);
	free (data);
	return (0);
}
