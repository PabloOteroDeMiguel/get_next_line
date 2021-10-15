/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:24:02 by potero            #+#    #+#             */
/*   Updated: 2021/10/14 17:18:21 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_strjoin(char const *s1, char const *s2);
void    *ft_calloc_bzero(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
#endif
