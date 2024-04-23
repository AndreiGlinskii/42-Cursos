/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:11:04 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/22 17:11:05 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *bufer_tmp, int *eol_loc)
{
	size_t	len;
	char	*str;

	len = 0;
	while (bufer_tmp[len] && bufer_tmp[len] != '\n')
		len++;
	len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_memcpy(str, bufer_tmp, len);
	str[len] = '\0';
	if (len > 0 && str[len - 1] == '\n')
		*eol_loc = len - 1;
	return (str);
}

/* se utiliza para inicializar una linea de textoo a partir de un fragmento
de datos almacenado en un bufer temporal
1. size_t - para almacenar la longitud de la linea de texto
2. *str - para almacenar la linea de texto inicializada
3. hacemos un bucle para colcular la longitud de nuestro bufer temporal 
hasta el primer caracter de nueva linea ('\n) o hasta el final de la cadena
4. Usamos len++ dos veces porque 1 "len++" se utiliza para calcular la longitud
de la linea en "bufer_tmp" mientras que el segundo "len++" se utiliza
para garantizar que el tamaño de memoria asignado a "str" sea lo 
suficienmente grande para contener toda la linea
5. memcpy*/ memcpy

size_t	find_eol_position(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (i < BUFFER_SIZE || str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
