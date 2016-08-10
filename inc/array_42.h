/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:41:13 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 11:15:25 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_42_H
# define ARRAY_42_H

# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "memory_42.h"
# include "stdlib_42.h"
# include "string_42.h"

# define ARRAY_INIT_CAPACITY	8
# define ARRAY_GROWTH_FACTOR	2
# define TARRAY_MAX(v)			((v)->max)
# define TARRAY_COUNT(v)		((v)->count)
# define TARRAY_DATA(v)			((v)->data)
# define TARRAY_GET(v, i)		((i) >= (v)->count ? NULL : (v)->data[i])
# define TARRAY_SET(v, i, e)	((v)->data[i] = (i) >= (v)->count ? NULL : e)
# define TARRAY_FREE(v)			free((v)->data)
# define TARRAY_ISEMPTY(v)		(!((v)->count))

/*
** new
*/
t_array	*array_new(size_t size);
void	*array_init(t_array *v, size_t size);

/*
** resize
*/
t_array	*array_add(t_array *v, void *e);
t_array	*array_insert(t_array *v, size_t i, void *e);

/*
** getset
*/
void	*array_replace(t_array *v, size_t i, void *e);
void	*array_get(t_array *v, size_t i);
int		array_indexof(t_array *v, void *e);
void	*array_iterator(t_array *v);

/*
** delete
*/
void	*array_remove(t_array *v, size_t i);
void	array_destroy(t_array *v);
void	array_clear(t_array *v);
void	array_reset(t_array *v);

/*
** transform
*/
t_array	*array_copy(t_array *v);
t_array	*array_strsplit(char *str, char c);

#endif
