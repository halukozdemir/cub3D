/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halozdem <halozdem@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:54:29 by halozdem          #+#    #+#             */
/*   Updated: 2025/04/24 18:54:31 by halozdem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_line
{
	char			*content;
	int				length;
	struct s_line	*next;
}					t_line;

char	*get_next_line(int fd);
t_line	*ft_gnl_lstnew(char *content);
t_line	*ft_gnl_lstlast(t_line *lst);
void	ft_gnl_lstadd_back(t_line **lst, t_line *new);
void	ft_gnl_lstclear(t_line **lst, void (*del)(void *));
void	*ft_gnl_calloc(size_t nmemb, size_t size);
#endif