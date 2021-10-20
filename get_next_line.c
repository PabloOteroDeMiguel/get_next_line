/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 12:49:35 by potero-d          #+#    #+#             */
/*   Updated: 2021/10/20 13:27:50 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

size_t	ft_read(char *buff, char *rest)
{
	char	*buff;
	char	*aux;

	buff = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
	read(fd, buff, BUFFER_SIZE);
	if (rest != 0)
	{
		aux = buff;
		buff = ft_strjoin(rest, aux);
		free(rest);
		free(aux);
	}
	return (ft_strlen(buff));

size_t	ft_notn(char *print, *buff)
{
	char	*aux;

	aux = print;
	print = ft_strjoin(aux, buff);
	free(aux);
	free(buff);
	buff = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
	read(fd, buff, BUFFER_SIZE);
	return (ft_strlen(buff));
}

char	ft_end(char *buff, char *print, char *rest)
{
	char	*aux;
	char	*aux2;

	aux2 = ft_substr(buff, 0, i[1] + 1);
	aux = ft_strjoin(print, aux2);
	free(aux);
	free(print);
	if (BUFFER_SIZE > 1)
		rest = ft_substr(buff, i[1] + 1, (i[0] - i + 1));
	free(buff);
	return(aux);
}

char	*get_next_line(int fd)
{
	char	*print;
	char	*buff;
	char	*rest;
	size_t	i[2];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i[0] = ft_read(buff, rest);
	i[1] = 0;
	while (buff[i[1]] != '\n')	
	{
		if (i[1] == i[0] - 1)
		{
			i[0] = ft_notn(print, buff);
			if (i[0] == 0)
				break;
			i[1] = -1;
		}
		i[1]++;
	}
	return (ft_end(buff, print, rest));
}
