/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:22:42 by potero            #+#    #+#             */
/*   Updated: 2021/10/14 16:21:56 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	char	*print;
	char	*aux = NULL;
	size_t	i;
	size_t	c;
	static char	*rest;

	c = 1;
	buff = ft_calloc_bzero(c, (BUFFER_SIZE + 1));
 	read(fd, buff, BUFFER_SIZE);
	i = 0;
   	if (rest != '\0')
	{
		c++;
		print = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
 		print = ft_substr(rest, 0, ft_strlen(rest));
	}
	while (buff[i] != '\n')
	{
		if ((i == ft_strlen(buff)) && (c == 1))
		{	
			c++;
			print = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
			ft_strlcat(print, buff, (BUFFER_SIZE + 1));
			free(buff);
			buff = ft_calloc_bzero(c, (BUFFER_SIZE + 1));
			read(fd, buff, BUFFER_SIZE);
			i = -1;
		}

		else if ((c > 1) && (i == ft_strlen(buff)))
		{
			c++;
			aux = print;
			free(print);
			print =  ft_calloc_bzero(c, ((BUFFER_SIZE * c) + 1));
			ft_strlcat(print, aux, (BUFFER_SIZE * (c - 1)));
			ft_strlcat(print, buff, (ft_strlen(print) + i + 1));
			free(buff);
			buff = ft_calloc_bzero(c, (BUFFER_SIZE + 1));
			read(fd, buff, BUFFER_SIZE);
			i = -1;
		}
		i++;
	}
	if (c == 1)
		print = ft_substr(buff, 0, i);
	else if (buff[i] == '\n' && c > 1)
	{
		ft_strlcat(print, buff, (ft_strlen(print) + i + 1));
		rest = ft_substr(buff, i + 1, ft_strlen(buff));
	}
	return (print);
}

int	main(void)
{
	int		fd;
	char	*print;
	
	fd = open("ElQuijote.txt", O_RDONLY);
	if (fd == -1)
		return (write(1, "NULL\n", 5));
	print = get_next_line(fd);
	printf("%s\n", print);
	printf("--------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	printf("--------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
	printf("--------\n");
	print = get_next_line(fd);
	printf("%s\n", print);
}
