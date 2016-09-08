/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:16:16 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 19:04:49 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array		*array_insert(t_array *v, size_t i, void *e)
{
	char	*src;
	size_t	len;

	if (i > v->count)
		return (NULL);
	if (TARRAY_NEED_RESIZE(v))
		if (array_resize(v) == NULL)
			return (NULL);
	if (i == v->count)
		return (array_add(v, e));
	src = TARRAY_GET(v, i);
	len = (v->count - i) * v->elem_size;
	ft_memmove(src + v->elem_size, src, len);
	array_set(v, i, e);
	v->count += 1;
	return (v);
}
