/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 12:23:49 by djean             #+#    #+#             */
/*   Updated: 2016/08/11 12:23:50 by djean            ###   ########.fr       */
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
	return (v->data[v->iterator++]);
}

void	array_iterator_prev(t_array *v)
{
	if (v->iterator > 0)
		--v->iterator;
}

void	array_iterator_next(t_array *v)
{
	if (v->iterator < v->count)
		++v->iterator;
}
