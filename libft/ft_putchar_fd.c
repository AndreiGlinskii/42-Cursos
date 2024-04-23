/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:11:14 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/27 16:11:15 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/* El descriptor de archivo `1` corresponde a la salida estándar (stdout)
El descriptor `2` corresponde a la salida de error estándar (stderr)
y otros descriptores pueden estar asociados a archivos específicos
O dispositivos según sea necesario. */