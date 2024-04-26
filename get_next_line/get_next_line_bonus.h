/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:07:35 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/24 18:07:37 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512 /*por defecto se establece en 512 bytes
si no se define previamente*/
# endif
# if BUFFER_SIZE > 1024 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# ifndef MAX_OPEN_FILES
#  define MAX_OPEN_FILES 512
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin_gnl(char *s1, char *s2, int *eol_loc);
char	*get_next_line(int fd);
char	*ft_get_line(char *buffer_tmp, int *eol_loc);
size_t	find_eol_position(char *str);
char	*read_extract_line(char *line, char *buffer_tmp, int *eol_loc, int fd);

#endif
