/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:18:27 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:29:38 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_vector.h"

void	*ft_vector_resize(t_vector *v)
{
	void	*new;
	size_t	s;

	s = sizeof(void*) * v->max * VECTOR_GROWTH_FACTOR;
	new = ft_realloc(v->data, s, v->total * sizeof(void*));
	if (new == NULL)
		return (NULL);
	v->data = new;
	v->max *= VECTOR_GROWTH_FACTOR;
	return (v);
}
