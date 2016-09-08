/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_getset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 15:13:49 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_get(t_array *v, size_t i)
{
	if (i >= v->count)
		return (NULL);
	return (TARRAY_GET(v, i));
}

void	array_set(t_array *v, size_t i, void *e)
{
	if (i < v->count)
		ft_memcpy(TARRAY_GET(v, i), e, v->elem_size);
}
