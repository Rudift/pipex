/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-28 12:26:24 by vdeliere          #+#    #+#             */
/*   Updated: 2025-02-28 12:26:24 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//Fonction principale qui gere le piping

void	pipex(t_data *data)
{
	if (pipe(data->pipe_fd) == -1)
		error_exit("Error with creating pipe", data);
}
