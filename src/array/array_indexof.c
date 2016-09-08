/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_indexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 15:54:59 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 15:52:29 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Search if the pointer e belongs to the array range
** Return the index or -1 on error
*/

int		array_indexof(t_array *v, void *e)
{
	if (TARRAY_IN_RANGE(v, e))
		return (((uintptr_t)e - (uintptr_t)v->data) / v->elem_size);
	return (-1);
}
