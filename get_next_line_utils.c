/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:47:50 by potero-d          #+#    #+#             */
/*   Updated: 2021/10/14 17:55:09 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	unsigned char	*dst1;
	unsigned char	*src1;

	i = 0;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize > 0)
	{	
		while ((i < dstsize - 1) && (i < ft_strlen(src)))
		{
			dst1[i] = src1[i];
			i++;
		}
		dst1[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len == 1 && start >= ft_strlen(s))
	{
		str = malloc(1);
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
	{	
		ft_strlcpy(str, &s[start], len + 1);
	}
	else
		ft_strlcpy(str, "", 1);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	z;

	z = ft_strlen(dst);
	j = ft_strlen(dst);
	i = 0;
	if ((z < dstsize - 1) && dstsize > 0)
	{
		while ((j < dstsize - 1) && (src[i] != '\0'))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (z >= dstsize)
		z = dstsize;
	return (z + ft_strlen(src));
}

void	*ft_calloc_bzero(size_t count, size_t size)
{
	void	*str;
	size_t	i;
	char	*s;

	i = 0;
	str = malloc(count * size);
	s = (char *)str;
	if (!str)
		return (0);
	while (i < (count * size))
	{
		s[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (str);
}
