/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:41:37 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:05:12 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_42.h"

/*
** Alloue un nouveau vector et copie la structure *v
** Dans le nouvel espace.
*/

t_vector	*ft_vector_copy(t_vector *v)
{
	t_vector	*cp;

	if ((cp = ft_vector_new(FT_VECTOR_MAX(v))) == NULL)
		return (NULL);
	FT_VECTOR_TOTAL(cp) = FT_VECTOR_TOTAL(v);
	ft_memcpy(FT_VECTOR_DATA(cp), FT_VECTOR_DATA(v),
			FT_VECTOR_TOTAL(v) * sizeof(void*));
	return (cp);
}
