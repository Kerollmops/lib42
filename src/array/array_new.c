/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:31:27 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array	*array_new(size_t size)
{
	t_array	*v;

	v = ft_memalloc(sizeof(t_array));
	if (v == NULL)
		return (NULL);
	if ((array_init(v, size)) == NULL)
	{
		free(v);
		return (NULL);
	}
	return (v);
}

void	*array_init(t_array *v, size_t size)
{
	size_t	s;

	s = (size == 0) ? ARRAY_INIT_CAPACITY : size;
	v->max = s;
	v->count = 0;
	v->data = ft_memalloc(sizeof(void*) * s);
	if (v->data == NULL)
		return (NULL);
	return (v);
}
