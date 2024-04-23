/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <aglinski@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:59:52 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/12 17:59:54 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char format, va_list arg)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_hex_pointer(va_arg(arg, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_putinbr(va_arg(arg, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(arg, unsigned int),
				"0123456789abcdef", 0));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(arg, unsigned int),
				"0123456789ABCDEF", 0));
	else if (format == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_format(const char *format, va_list arg, int *i)
{
	int	count;

	count = 0;
	if (*(format + *i) == '%' && *(format + *i + 1) != '\0')
	{
		(*i)++;
		count = ft_print_format(*(format + *i), arg);
		if (count == -1)
			return (-1);
	}
	else if (*(format + *i) != '%')
	{
		count = ft_putchar(*(format + *i));
		if (count == -1)
			return (-1);
	}
	(*i)++;
	return (count);
}

/* Esta funcion procesa una cadena de formato y una lista
de argumentos para formatear una salida
i - es un puntero a un entero que indica la posicion 
actual en la cadena
la expricion "format + *i + 1" se utiliza para acceder
al siguiente caracter despues del "%" en la cadena de formato
*/

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;
	int		res;

	va_start(arg, format);
	i = 0;
	count = 0;
	res = 0;
	if (format)
	{
		while (*(format + i))
		{
			res = ft_format(format, arg, &i);
			if (res == -1)
			{
				va_end(arg);
				return (-1);
			}
			count += res;
		}
	}
	va_end(arg);
	return (count);
}

/*1. va_list - se utiliza para declarar objetos que almacenan
informacion sobre la lista de argumentos variables en una funcion

2. va_arg - esta macro extrae el siguiente argumento de la lista
de argumentos variables. Toma dos argumentos: 1 - "va_list", 2 - es el 
tipo del argumento que se espera. "va_arg" devuelve el valor del siguiente
argumento en la lista y avanza el objeto "va_list" para que apunte al
siguiente numero 

3. va_start - esa macro inicializa un objeto de tipo "va_list"
para que puedes comenzar a tarbajar con la lista de argumentos variables
Toma 2 argumentos 1 - "va_list" (arg),
2 - es el ultio argumento fijo de la funcion

4. va_copy - se utiliza para crear una copia de un objeto "va_list"

5. va_end - se realiza tareas de limpieza y libera los recursos asociados
con el objeto "va_list" 
*/

/* int	main(void)
{
	char	*str = "Salam aleikum";
	int		num = 42;
	unsigned int	unum = 42;
	void	*ptr = &num;

	ft_printf("Imprimir un caracter: %c\n", 'N');
	ft_printf("Imprimir una cadena: %s\n", str);
	ft_printf("Un puntero de void * en formato hexadecimal: %p\n", ptr);
	ft_printf("Imprimir un nuemero decimal = %d\n", num);
	ft_printf("Imprimir un numero entero: %i\n", num);
	ft_printf("Imprimir un numero decimal sin signo: %u\n", unum);
	ft_printf("Imprimir un numero hexadecimal en menusculas: %x\n", num);
	ft_printf("Imprimir un numero hexadecimal en MAYUsculas: %X\n", num);
	ft_printf("Broo, lo siento: %%\n");
	ft_printf("Imprimir mis datos: 
	privet soy %s, mi IP es: %u en Sibir.\n", "Marvin", 42);
	return (0);
}
*/