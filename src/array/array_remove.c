/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 19:35:29 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 20:04:39 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Remove an element from the array and store it in *removed
** *removed should be a memory space large enough to hold an element
** If *removed == NULL, no backup is made
*/

void	*array_remove(t_array *v, size_t i, void *removed)
{
	char	*p;
	size_t	len;

	if (i >= v->count)
		return (NULL);
	p = TARRAY_GET(v, i);
	if (removed != NULL)
		ft_memcpy(removed, p, v->elem_size);
	len = (v->count - i) * v->elem_size;
	ft_memmove(p, p + v->elem_size, len);
	v->count -= 1;
	if (v->iterator > i)
		--v->iterator;
	return (removed);
}

void	*array_remove_elem(t_array *v, void *e)
{
	int	index;

	index = array_indexof(v, e);
	if (index == -1)
		return (NULL);
	return (array_remove(v, index, NULL));
}
