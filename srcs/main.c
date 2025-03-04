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

void	error_exit (char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char *ft_getenv(char **envp)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	if (envp[i][j] != '\0')
	{
		while (envp[i][j] != '=')
			j++;
		j++;
		return (&envp[i][j]);
	}
	else
		return (NULL);
}

void data_init(t_data *data, char **av, char **envp)
{
	data->params = av;
	data->path = ft_getenv(envp);
	printf("%s\n", data->path);
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
		error_exit("parse error\n");
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	data_init(data, av, envp);
	pipex(data);
	forker(data);
}