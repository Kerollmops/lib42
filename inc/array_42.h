/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/09/27 16:17:04 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_42_H
# define ARRAY_42_H

# include <stdlib.h>
# include <stdint.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "memory_42.h"
# include "stdlib_42.h"
# include "string_42.h"

# define TARRAY_MIN_SIZE		8
# define TARRAY_GROWTH_FACTOR	2
# define TARRAY_NEED_RESIZE(v)	((v)->count + 1 >= (v)->max)
# define TARRAY_MAX(v)			((v)->max)
# define TARRAY_COUNT(v)		((v)->count)
# define TARRAY_DATA(v)			((v)->data)
# define TARRAY_GET(v, i)		((char*)(v)->data + ((v)->elem_size * (i)))
# define TARRAY_ADDR_MIN(v)		((v)->data)
# define TARRAY_ADDR_MAX(v)		((void*)TARRAY_GET(v, (v)->count))
# define TARRAY_IN_RANGE(v, p)	((p) >= (v)->data && (p) < TARRAY_ADDR_MAX(v))
# define TARRAY_FREE(v)			free((v)->data)
# define TARRAY_ISEMPTY(v)		(!((v)->count))
# define TARRAY_ITER(v)			((v)->iterator)
# define TARRAY_RESET_ITER(v)	(v)->iterator = 0

t_array	*array_new(size_t size, size_t elem_size);
void	*array_init(t_array *v, size_t size, size_t elem_size);
void	*array_resize(t_array *v);
void	*array_get(t_array *v, size_t i);
void	array_set(t_array *v, size_t i, void *e);
int		array_indexof(t_array *v, void *e);
void	*array_create_node(t_array *v);
t_array	*array_add(t_array *v, void *e);
void	*array_replace(t_array *v, size_t i, void *e, void *old);
t_array	*array_insert(t_array *v, size_t i, void *e);
void	*array_remove(t_array *v, size_t i, void *removed);
void	*array_remove_elem(t_array *v, void *e);
void	array_delete(t_array *v, size_t i);
void	array_destroy(t_array *v);
void	array_reset(t_array *v);
t_array	*array_copy(t_array *v);
t_array	*array_strsplit(char *str, char c);
void	*array_iterator(t_array *v);
void	array_iterator_prev(t_array *v);
void	array_iterator_next(t_array *v);
void	array_iterator_set(t_array *v, size_t index);

#endif
