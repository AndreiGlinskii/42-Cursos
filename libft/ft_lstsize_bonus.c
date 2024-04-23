/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:42:49 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/28 11:42:57 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

/* int main(void)
{
    t_list *head = NULL;

    // Creamos una lista enlazada simple con algunos elementos
    ft_lstadd_back(&head, ft_lstnew("Hello"));
    ft_lstadd_back(&head, ft_lstnew("world"));
    ft_lstadd_back(&head, ft_lstnew("from"));
    ft_lstadd_back(&head, ft_lstnew("OpenAI"));

    // Obtenemos el tamaño de la lista
    int size = ft_lstsize(head);

    // Imprimimos el tamaño de la lista
    printf("El tamaño de la lista es: %d\n", size);

    // Liberamos la memoria de la lista
    ft_lstclear(&head, free);

    return 0;
} */
