/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:00:18 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:29:37 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_vector.h"

t_vector	*ft_vector_new(size_t size)
{
	t_vector	*v;

	v = ft_memalloc(sizeof(t_vector));
	if (v == NULL)
		return (NULL);
	if ((ft_vector_init(v, size)) == NULL)
	{
		free(v);
		return (NULL);
	}
	return (v);
}
