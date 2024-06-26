/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:50:28 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/27 16:50:29 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

/*
#include <fcntl.h>

int main() 
{
	int fd;
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	
	if (fd == -1)
	{
	
	return (1);

	}
		ft_putnbr_fd(34, fd);
	
	close (fd);

	return (0);
    
}
*/