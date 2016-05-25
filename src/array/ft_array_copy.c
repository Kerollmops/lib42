/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:41:37 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:56:59 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Alloue un nouveau array et copie la structure *v
** Dans le nouvel espace.
*/

t_array	*ft_array_copy(t_array *v)
{
	t_array	*cp;

	if ((cp = ft_array_new(FT_ARRAY_MAX(v))) == NULL)
		return (NULL);
	FT_ARRAY_TOTAL(cp) = FT_ARRAY_TOTAL(v);
	ft_memcpy(FT_ARRAY_DATA(cp), FT_ARRAY_DATA(v),
			FT_ARRAY_TOTAL(v) * sizeof(void*));
	return (cp);
}
