/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:10:47 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:05:13 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_42.h"

void	*ft_vector_init(t_vector *v, size_t size)
{
	size_t	s;

	s = (size == 0) ? VECTOR_INIT_CAPACITY : size;
	v->max = s;
	v->total = 0;
	v->data = ft_memalloc(sizeof(void*) * s);
	if (v->data == NULL)
		return (NULL);
	return (v);
}
