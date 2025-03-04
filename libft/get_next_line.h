/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:29:54 by vdeliere          #+#    #+#             */
/*   Updated: 2024/12/02 09:59:57 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>

/*Principales*/
char			*get_next_line(int fd);

/*Utilitaires*/
void			*st_calloc(size_t nmemb, size_t size);
void			st_bzero(void *s, size_t n);
char			*st_strchr(const char *s, int c);
char			*st_strjoin(char const *s1, char const *s2);
char			*append_buffer(char *basin_buffer, char *read_buffer);
int				st_strlen(const char *s, char param);
#endif