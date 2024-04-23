/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:14:57 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/14 15:15:01 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;
	size_t	all;

	i = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	all = dstlen + srclen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (src[i] != '\0' && dstlen + i + 1 < dstsize)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (all);
}

/* int main(void)
{
	char dst[20] = "Hello";
	const char *src = " world!";
	size_t dstlen = sizeof(dst);

	printf("Before ft_strlcat: dst = %s\n", dst);

	size_t res = ft_strlcat(dst, src, dstlen);

	printf("After ft_strlcat: dst = %s\n", dst);
	printf("Return value: %zu\n", res);

	return (0);
} */