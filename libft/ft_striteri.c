/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:35:52 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/27 15:35:54 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void test_function(unsigned int i, char *s) 
{
	i = 0;
	while (*s >= 'a' && *s <= 'z')
		s[0] -= 32;
}
#include <stdio.h>
int main ()
{
	char str [] = "papitas";
	ft_striteri(str, test_function);
	printf("%s\n", str);
	return (0);
}
*/