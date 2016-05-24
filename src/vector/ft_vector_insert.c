/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:17:35 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:05:13 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_42.h"

void	*ft_vector_insert(t_vector *v, size_t i, void *e)
{
	void	*tmp;

	if (i > v->total)
		return (NULL);
	if (v->total + 1 >= v->max)
		if (ft_vector_resize(v) == NULL)
			return (NULL);
	while (i < v->total)
	{
		tmp = FT_VECTOR_GET(v, i);
		FT_VECTOR_SET(v, i, e);
		e = tmp;
		++i;
	}
	if (i == v->total)
		return (ft_vector_add(v, e));
	v->total++;
	return (v);
}
