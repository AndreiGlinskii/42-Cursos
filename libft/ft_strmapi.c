/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:59:22 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/27 14:59:23 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (0);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* char	upper_map(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	str;
	char	*mapped_str;

	str = "salam alaikum";
	mapped_str = ft_strmapi(str, &upper_map);
	printf("Cadena original: %s\n", str);
	printf("Cadena mapeada:  %s\n", mapped_str);
	free(mapped_str);
	return (0);
} */
