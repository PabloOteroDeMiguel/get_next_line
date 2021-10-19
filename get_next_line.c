/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:22:42 by potero            #+#    #+#             */
/*   Updated: 2021/10/18 16:56:06 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	char	*print;
	char	*aux;
	size_t	i;
	static char	*rest;

	buff = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
 	read(fd, buff, BUFFER_SIZE);
	printf("buff: %p\n", buff);
	print = malloc(sizeof(char) * (1));
	print[0] = 0;
	printf("p: %p\n", print);
	if (fd == -1 || ft_strlen(buff) == 0)
		return (0);
	if (rest != 0)
	{
		aux = ft_substr(buff, 0, ft_strlen(buff));
		free(buff);
		buff = ft_strjoin(rest, aux);
		free(rest);
		free(aux);
	}
	i = 0;
	while (buff[i] != '\n')
	{
	 	if (i == ft_strlen(buff) - 1)
		{
			//aux = ft_substr(print, 0, ft_strlen(print) - 1);
			aux = print;
			printf("aux: %zu - %p\n", i, aux);		
			free(print);
			printf("printF: %p\n", print);
			print  = ft_strjoin(aux, buff);
			printf("printJ: %p\n", print);
//			free(aux);
//			aux = 0;
			free(buff);
			buff = ft_calloc_bzero(1, (BUFFER_SIZE + 1));
			read(fd, buff, BUFFER_SIZE);
			if (ft_strlen(buff) == 0)
				break;
			i = -1;
		}
		i++;
	}
	aux = ft_strjoin(print, (ft_substr(buff, 0, i)));
	printf("auxO %p\n", aux);
	free(print);
	if (BUFFER_SIZE > 1)
		rest = ft_substr(buff, i + 1, (ft_strlen(buff) - i + 1));
	free(buff);
	return (aux);
}

int	main(void)
{
	int		fd;
	char	*print;
	
	fd = open("123.txt", O_RDONLY);
	if (fd == -1)
		return (write(1, "NULL\n", 5));

	print = get_next_line(fd);	
	system("leaks a.out");
	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	close(fd);
}
/*
int				main()
{
	int			fd;
	char		*str;
	int			i;

	i = 0;
	fd = open("123.txt", O_RDONLY);
// 	get_next_line(fd, &str);
//	printf("%s", str); 
	while ((str = get_next_line(fd)))
	{
	//	printf("line %i=>%s\n", i + 1, str);
		free(str);
		i++;
	}
//	printf("%s\n", str);
	system("leaks a.out");
	return (0);
}*/
