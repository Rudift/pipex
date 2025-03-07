/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-28 12:20:41 by vdeliere          #+#    #+#             */
/*   Updated: 2025-02-28 12:20:41 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Gestion des fichiers (open, close, dup2)

void	open_infile(t_data *data)
{
	if (access(data->params[1], R_OK) == -1)
		error_exit("Access infile error", data);
	data->infile = open(data->params[1], O_RDONLY);
	if (data->infile == -1)
		error_exit("Open infile error", data);
}

void	open_outfile(t_data *data)
{
	if (access(data->params[4], W_OK) == -1)
		error_exit("Access outfile error\n", data);
	data->outfile = open(data->params[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile == -1)
		error_exit("Open outfile error\n", data);
}
