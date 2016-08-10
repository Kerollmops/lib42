/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:31:27 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

static void	*array_resize(t_array *v)
{
	void	*new;
	size_t	s;

	s = sizeof(void*) * v->max * ARRAY_GROWTH_FACTOR;
	new = ft_realloc(v->data, s, v->count * sizeof(void*));
	if (new == NULL)
		return (NULL);
	v->data = new;
	v->max *= ARRAY_GROWTH_FACTOR;
	return (v);
}

t_array		*array_add(t_array *v, void *e)
{
	if (v->count + 1 >= v->max)
		if (array_resize(v) == NULL)
			return (NULL);
	v->data[v->count++] = e;
	return (v);
}

t_array		*array_insert(t_array *v, size_t i, void *e)
{
	unsigned char	**src;
	size_t			len;

	if (i > v->count)
		return (NULL);
	if (v->count + 1 >= v->max)
		if (array_resize(v) == NULL)
			return (NULL);
	if (i == v->count)
		return (array_add(v, e));
	src = (unsigned char **)(v->data + i);
	len = (v->count - i) * sizeof(void*);
	ft_memmove(src + 1, src, len);
	v->data[i] = e;
	v->count++;
	return (v);
}
