/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:17:58 by djean             #+#    #+#             */
/*   Updated: 2016/05/13 14:51:31 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	*ft_vector_add(t_vector *v, void *e)
{
	if (v->total + 1 >= v->max - 1)
		if (ft_vector_resize(v) == NULL)
			return (NULL);
	v->data[v->total++] = e;
	return (v);
}