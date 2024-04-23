/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:34:17 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/18 17:34:19 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*bzero;
	size_t	all;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	all = count * size;
	bzero = (void *)malloc(all);
	if (!bzero)
		return (0);
	ft_bzero (bzero, all);
	return (bzero);
}
