/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:33:11 by aglinski          #+#    #+#             */
/*   Updated: 2024/03/28 15:33:12 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	t_list	*content;

	new_lst = 0;
	while (lst)
	{
		content = f(lst -> content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst -> next;
	}
	return (new_lst);
}

/* void	*duplicate_int(void *content)
{
	int	*original = (int *)content;
	int	*copy = malloc(sizeof(int));
	if (!copy)
		return (NULL);
	*copy = *original;
	return (copy);
}

// Función para liberar la memoria de un entero (solo como ejemplo)
void	free_int(void *content)
{
	free(content);
}

// Función para imprimir un entero (solo como ejemplo)
void	print_int(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *((int *)lst->content));
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*lst = NULL;
	t_list	*new_lst = NULL;
	int		arr[] = {1, 2, 3, 4, 5};

	// Crear la lista original
	for (int i = 0; i < 5; i++)
		ft_lstadd_back(&lst, ft_lstnew(&arr[i]));

	// Aplicar la función de mapeo a la lista original
	new_lst = ft_lstmap(lst, &duplicate_int, &free_int);

	// Imprimir la lista mapeada
	printf("Lista mapeada: ");
	print_int(new_lst);

	// Liberar memoria de la lista original y la lista mapeada
	ft_lstclear(&lst, &free);
	ft_lstclear(&new_lst, &free);

	return (0);
} */
