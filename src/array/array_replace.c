/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 11:02:40 by djean             #+#    #+#             */
/*   Updated: 2016/09/07 17:57:03 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Set le nouvel élément à la place i
** Et retourne l'ancien élément
** old est un emplacement mémoire qui va contenir l'élément remplacé
** Si old == NULL, alors l'élément est simplement écrasé
*/

void	*array_replace(t_array *v, size_t i, void *e, void *old)
{
	void	*p;

	if (i >= v->count)
		return (NULL);
	if (old != NULL)
	{
		p = TARRAY_GET(v, i);
		ft_memcpy(old, p, v->elem_size);
	}
	array_set(v, i, e);
	return (old);
}
