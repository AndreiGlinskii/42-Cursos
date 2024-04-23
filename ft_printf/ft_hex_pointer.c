/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:54:35 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/16 15:54:36 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_pointer(unsigned long point)
{
	int	res;
	int	hex;

	res = ft_putstr("0x");
	if (res == -1)
		return (-1);
	hex = ft_putnbr_base(point, "0123456789abcdef", 0);
	if (hex == -1)
		return (-1);
	return (res + hex);
}

/* ft_hex_poinet - se utiliza para imprimir un puntero
en formato hexadecimal (16), comenzando con "0x" 
seguido de la representacion hexadecimal del puntero en sí
1. "0x" es una convencion comun preceder los valores
hexadecimales con "0x" para distinguirlos de los 
valores decimales (10)
2. ft_putnbr_base se llama para imprimir la representacion hexadecimal
del puntero "point"
3. res + hex - se retorna la suma de la longitud de "0x"
y la longitud de la representacion hexadecimal del puntero */
