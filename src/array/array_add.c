/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:35:26 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 15:13:47 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array		*array_add(t_array *v, void *e)
{
	if (TARRAY_NEED_RESIZE(v))
		if (array_resize(v) == NULL)
			return (NULL);
	ft_memcpy(TARRAY_GET(v, v->count), e, v->elem_size);
	v->count += 1;
	return (v);
}
