/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:41:13 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:07:12 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_42_H
# define VECTOR_42_H

# include <stdlib.h>
# include "memory_42.h"
# include "string_42.h"
# include "stdlib_42.h"

# define VECTOR_INIT_CAPACITY 8
# define VECTOR_GROWTH_FACTOR 2
# define FT_VECTOR_TOTAL(v)		((v)->total)
# define FT_VECTOR_MAX(v)		((v)->max)
# define FT_VECTOR_FREE(v)		free((v)->data)
# define FT_VECTOR_DATA(v)		((v)->data)
# define FT_VECTOR_RESET(v)		((v)->total = 0)
# define FT_VECTOR_GET(v, i)	((i) >= (v)->total ? NULL : (v)->data[i])
# define FT_VECTOR_SET(v, i, e)	((v)->data[i] = (i) >= (v)->total ? NULL : e)

typedef struct	s_vector
{
	void	**data;
	size_t	max;
	size_t	total;
}				t_vector;

t_vector		*ft_vector_new(size_t size);
void			*ft_vector_init(t_vector *v, size_t size);
void			*ft_vector_add(t_vector *v, void *e);
void			*ft_vector_set(t_vector *v, size_t i, void *e);
void			*ft_vector_replace(t_vector *v, size_t i, void *e);
void			*ft_vector_remove(t_vector *v, size_t i);
void			*ft_vector_get(t_vector *v, size_t i);
void			*ft_vector_resize(t_vector *v);
void			ft_vector_destroy(t_vector *v);
void			*ft_vector_insert(t_vector *v, size_t i, void *e);
void			ft_vector_clear(t_vector *v);
t_vector		*ft_vector_copy(t_vector *v);
int				ft_vector_indexof(t_vector *v, void *e);
t_vector		*ft_vector_strsplit(char *str, char c);

#endif
