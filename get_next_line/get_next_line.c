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

char	*ft_get_line(char *buffer_tmp, int *eol_loc)
{
	size_t	len;
	char	*str;

	len = 0;
	while (buffer_tmp[len] && buffer_tmp[len] != '\n')
		len++;
	len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_memcpy(str, buffer_tmp, len);
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
5. memcpy - copiamos la llongitud de nuestro bufer temporal
a nuestra linea de texto
6. Terminamos nuestra linea de texto con un caracter nulo
7. *elo_loc = len - 1 - es para designar que  alli esta la ubicacion 
del caraccterde fin de linea en "str"*/

size_t	find_eol_position(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (i < BUFFER_SIZE || str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

/* eol_loc - esta variable se utiliza para almacenar la direccion
de memoria de un entero.

esta funcion se utiliza para encontrar la ubicacion del caracter
de fin linea ('\n') en el bufer de lectura
1. "i + 1" - es para tener en cuenta que es la posicion del caracter
de nueva linea*/

char	*read_extract_line(char *line, char *buffer_tmp, int *eol_loc, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	len;
	ssize_t	bytes_read;

	while (*eol_loc == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			ft_bzero(buffer_tmp, (BUFFER_SIZE + 1));
			return (0);
		}
		len = find_eol_position(buffer);
		ft_strlcpy_gnl(buffer_tmp, &buffer[len], (BUFFER_SIZE + 1));
		buffer[len] = '\0';
		line = ft_strjoin_gnl(line, buffer, eol_loc);
		if (bytes_read == 0)
		{
			ft_bzero(buffer_tmp, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

/* La diferencia entre size_t y ssize_t - "size_t" se utiliza para representar
tamaños de objetos y matrices, mientras que "ssize_t" se utiliza para 
representar resultados de operaciones de lectura/escritura y llamadas a 
sistema en las que se necesita un tipo de datos con signo para manejar
errores y valores negativos. "size_t" es un tipo de datos sin signo
pero "ssize_t" con signo y puede representar valores negativos

Esta funcion se utiliza para leer de un archivo y extraer lineas del buffer
de lectura.

"char buffer[BUFFER_SIZE + 1]" se inicializa un buffer de lectura de tamaño fijo
("BUFFER_SIZE + 1" es para almacenar '\0')

"ssize_t bytes_read" se inicializa una variable para almacenar el numero
de bytes leidos de la llamada a la funcion lectura

"while (*eol_loc == -1)" se ejecuta un bucle mientras no se haya encontrado 
un caracter de fin de linea en la linea actual

"bytes_read = read(fd, buffer, BUFFER_SIZE)" se lee datos del archivo
asociado al descriptor de archivo "fd" en el "buffer". El numero de bytes
leidos se almacena en la variable "bytes_read"

"if (bytes_read == -1)" si se produce un error al leer del archivo, se libera
la memoria asignada a la linea, se limpia el buffer y se devuelve "0"

"ft_strlcpy_gnl(buffer_tmp, &buffer[len], (BUFFER_SIZE + 1))" se copia
el contenido del buffer temporal "buffer_tmp" a partir de la posicion
despues del caracter de nueva linea encontrado en el buffer leido "buffer".
Esto se hace para preservar los datos que no forman parte de la linea
actual para su uso en la proxima iteracion

"line = ft_strjoin_gnl(line, buffer, eol_loc)" concatenacion de lineas

"if (bytes_read == 0)" si se ha llegado al final del archivo,
se limpia el buffer y se sale del bucle
*/

char	*get_next_line(int fd)
{
	static char	buffer_tmp[BUFFER_SIZE + 1];
	char		*line;
	int			eol_loc;

	eol_loc = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_get_line(buffer_tmp, &eol_loc);
	if (!line)
		return (0);
	ft_strlcpy_gnl(buffer_tmp, &buffer_tmp[eol_loc + 1], BUFFER_SIZE + 1);
	line = read_extract_line(line, buffer_tmp, &eol_loc, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}

/* Esta funcion se utiliza para leer una linea a la vez de un archivo

"static char buffer_tmp[BUFFER_SIZE + 1]" se inicializa un buffer
estatico para almacenar cualquier dato no procesado de 
lecturas anteriores

"line = ft_get_line(buffer_tmp, &eol_loc)" es para obtener la proxima linea
disponible del bufer. Esta funclion tambien actualiza "eol_loc" con la 
ubicacion del caracter de nueva linea si se encuentra

"ft_strlcpy_gnl(buffer_tmp, &buffer_tmp[eol_loc + 1], BUFFER_SIZE + 1)" 
se actualiza el bufer temporal ("buffer_tmp") eliminando la linea leida
para que el proximo llamado a "read_extract_line" no vuelva a leer 
la misma linea

"line = read_extract_line(line, buffer_tmp, &eol_loc, fd)" se llama para
leer el resto de la linea del archivo, esta funcion itera hast que 
encuentra un caracter de nueva linea o alcanza el final del archivo.
Durante cada iteracion actualiza "buffer_tmp" con los datos leidos
para que el proximo llamado a la funcion continue desde donde se detuvo*/

/* #include <fcntl.h>

int main(void)
{
	int fd1, fd2, fd3;
	char *line;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Error\n");
		return (1);
	}
	printf("Leyendo test1.txt:\n");
	while ((line = get_next_line(fd1)) != 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("Leyendo test2.txt:\n");
	while ((line = get_next_line(fd2)) != 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("Leyendo test3.txt:\n");
	while ((line = get_next_line(fd3)) != 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
} */
