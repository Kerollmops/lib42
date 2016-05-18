/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:47:50 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:05:13 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_42.h"

/*
** Set le nouvel élément à la place i
** Et retourne l'ancien élément
*/

void	*ft_vector_replace(t_vector *v, size_t i, void *e)
{
	void	*old;

	if (i >= FT_VECTOR_TOTAL(v))
		return (NULL);
	old = ft_vector_get(v, i);
	ft_vector_set(v, i, e);
	return (old);
}
