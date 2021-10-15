/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:22:42 by potero            #+#    #+#             */
/*   Updated: 2021/10/15 14:08:36 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	char	*print;
	char	*aux;
	char	*aux2=NULL;
	size_t	i;
	static char	*rest;

	buff = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
 	read(fd, buff, BUFFER_SIZE);
	print = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
	i = 0;
	while (buff[i] != '\n')
	{
		 if (i == ft_strlen(buff))
		{
			aux = print;
	//		free(print);
	//		print =  ft_calloc_bzero(c, ((BUFFER_SIZE * c) + 1));
	//		print = ft_strjoin(aux, print);
			print  = ft_strjoin(aux, buff);
			free(aux);
			free(buff);
			buff = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
			read(fd, buff, BUFFER_SIZE);
			i = -1;
		}
		i++;
	}
	aux = ft_strjoin(print, (ft_substr(buff, 0, i)));
	print = aux;
	printf("print: %s\n", print); 
	printf("buff: %s\n", buff);
	printf("i: %zu\n", i);
	printf("aux: %s\n", aux);
//	ft_strlcat(print, buff, (ft_strlen(print) + i + 1));
	print = aux;
	free(aux);
	aux = rest;
	rest = ft_substr(buff, i + 1, ft_strlen(buff));
	printf("aux2: %s\n", aux);
	if (aux != 0)
	//	printf("print2: %s\n", print);
		aux2 = ft_strjoin(aux, print);
		print = aux2;
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
	close(fd);
}
