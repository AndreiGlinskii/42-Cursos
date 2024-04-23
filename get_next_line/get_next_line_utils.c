/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <aglinski@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:42:58 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:00 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if ((!dst) && (!src))
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

void	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

void	ft_strjoin_gnl(const char *s1, const char *s2, int *eol_loc)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(len_s1 + len_s2 + 1);
	if (!s1 || !s2)
		return (0);
	if (!res)
	{
		free(s1);
		return (0);
	}
	ft_memcpy(res, s1, len_s1);
	free(s1);
	ft_memcpy(res + len_s1, s2, len_s2 + 1);
	if (len_s1 + len_s2 > 0 && *(res + len_s1 + len_s2 -1) == '\n')
		*eol_loc = 0;
	return (res);
}

/* se utiliza para unir dos cadenas de caracteres y mantener un seguimiento
de la posicion del salto de linea (\n)*/