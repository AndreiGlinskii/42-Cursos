/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <aglinski@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:01:13 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/12 18:01:14 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		return (ft_putinbr (n) + 1);
	}
	return (ft_putinbr(n));
}

/* Esta función escribe un número entero en la salida estandar */

int	ft_putinbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i = ft_putinbr(n / 10);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	i++;
	return (i);
}

/* esta funcion esta diseñada para imprimir un número entero no negativo
1. Si "putinbr" devuelve "-1" indica un error y la funcion devuelve "-1"
(es para manejar errorres)
2. "ft_putchar" se calcula el RESIDUO de "n" DIVIDO por 10 (ultimo dígito de "n")
y despues lo convierte en un carácter
*/
