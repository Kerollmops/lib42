/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:41:13 by djean             #+#    #+#             */
/*   Updated: 2016/06/29 11:13:11 by leonhart         ###   ########.fr       */
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
# define FT_ARRAY_TOTAL(v)		((v)->total)
# define FT_ARRAY_MAX(v)		((v)->max)
# define FT_ARRAY_FREE(v)		free((v)->data)
# define FT_ARRAY_DATA(v)		((v)->data)
# define FT_ARRAY_RESET(v)		((v)->total = 0)
# define FT_ARRAY_GET(v, i)		((i) >= (v)->total ? NULL : (v)->data[i])
# define FT_ARRAY_SET(v, i, e)	((v)->data[i] = (i) >= (v)->total ? NULL : e)

t_array	*ft_array_new(size_t size);
void	*ft_array_init(t_array *v, size_t size);
void	*ft_array_add(t_array *v, void *e);
void	*ft_array_set(t_array *v, size_t i, void *e);
void	*ft_array_replace(t_array *v, size_t i, void *e);
void	*ft_array_remove(t_array *v, size_t i);
void	*ft_array_get(t_array *v, size_t i);
void	*ft_array_resize(t_array *v);
void	ft_array_destroy(t_array *v);
void	*ft_array_insert(t_array *v, size_t i, void *e);
void	ft_array_clear(t_array *v);
t_array	*ft_array_copy(t_array *v);
int		ft_array_indexof(t_array *v, void *e);
t_array	*ft_array_strsplit(char *str, char c);

#endif
