/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:47:50 by djean             #+#    #+#             */
/*   Updated: 2016/05/13 13:34:32 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

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
