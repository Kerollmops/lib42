/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 12:23:49 by djean             #+#    #+#             */
/*   Updated: 2016/09/27 16:19:22 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_iterator(t_array *v)
{
	if (v->iterator >= v->count)
	{
		v->iterator = 0;
		return (NULL);
	}
	return (array_get(v, v->iterator++));
}

void	array_iterator_prev(t_array *v)
{
	if (v->iterator > 0)
		v->iterator -= 1;
}

void	array_iterator_next(t_array *v)
{
	if (v->iterator < v->count)
		v->iterator += 1;
}

void	array_iterator_set(t_array *v, size_t index)
{
	v->iterator = index;
}
