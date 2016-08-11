/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_getset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/08/11 12:23:34 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*array_get(t_array *v, size_t i)
{
	if (i >= v->count)
		return (NULL);
	return (v->data[i]);
}

int		array_indexof(t_array *v, void *e)
{
	size_t	i;

	i = 0;
	while (i < v->count)
	{
		if (v->data[i] == e)
			return (i);
		++i;
	}
	return (-1);
}

/*
** Set le nouvel élément à la place i
** Et retourne l'ancien élément
*/

void	*array_replace(t_array *v, size_t i, void *e)
{
	void	*old;

	if (i >= v->count)
		return (NULL);
	old = v->data[i];
	v->data[i] = e;
	return (old);
}
