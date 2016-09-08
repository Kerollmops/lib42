/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:09:45 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 15:13:42 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Return the first free node or create one if the array is full
*/

void	*array_create_node(t_array *v)
{
	if (TARRAY_NEED_RESIZE(v))
		if (array_resize(v) == NULL)
			return (NULL);
	v->count += 1;
	return (TARRAY_GET(v, v->count - 1));
}
