/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 15:13:49 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_resize(t_array *v)
{
	void	*new;
	size_t	new_size;

	new_size = v->elem_size * v->max * TARRAY_GROWTH_FACTOR;
	new = ft_realloc(v->data, new_size, v->count * v->elem_size);
	if (new == NULL)
		return (NULL);
	v->data = new;
	v->max *= TARRAY_GROWTH_FACTOR;
	return (v);
}
