/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:17:35 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:57:26 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*ft_array_insert(t_array *v, size_t i, void *e)
{
	unsigned char	**src;
	size_t			len;

	if (i > v->total)
		return (NULL);
	if (v->total + 1 >= v->max)
		if (ft_array_resize(v) == NULL)
			return (NULL);
	if (i == v->total)
		return (ft_array_add(v, e));
	src = (unsigned char **)(v->data + i);
	len = (v->total - i) * sizeof(void*);
	ft_memmove(src + 1, src, len);
	v->data[i] = e;
	v->total++;
	return (v);
}
