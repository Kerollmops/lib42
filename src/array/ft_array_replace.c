/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:47:50 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:57:43 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Set le nouvel élément à la place i
** Et retourne l'ancien élément
*/

void	*ft_array_replace(t_array *v, size_t i, void *e)
{
	void	*old;

	if (i >= FT_ARRAY_TOTAL(v))
		return (NULL);
	old = ft_array_get(v, i);
	ft_array_set(v, i, e);
	return (old);
}
