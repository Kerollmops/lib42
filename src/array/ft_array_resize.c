/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:18:27 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:57:50 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*ft_array_resize(t_array *v)
{
	void	*new;
	size_t	s;

	s = sizeof(void*) * v->max * ARRAY_GROWTH_FACTOR;
	new = ft_realloc(v->data, s, v->total * sizeof(void*));
	if (new == NULL)
		return (NULL);
	v->data = new;
	v->max *= ARRAY_GROWTH_FACTOR;
	return (v);
}
