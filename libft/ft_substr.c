/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:13:10 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:11 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (0);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

/*char	*res; == *substr */

/* return (ft_strdup(""));    es igual como:

	substr = (char *)malloc(1);
	if (!substr)
		return (NULL);
	substr[0] = '\0';  Establecer el terminador nulo para formar una cadena vacía
		return (substr); */