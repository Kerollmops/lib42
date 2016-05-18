/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_indexof.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:35:33 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:29:37 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_vector.h"

int	ft_vector_indexof(t_vector *v, void *e)
{
	size_t	i;

	i = 0;
	while (i < FT_VECTOR_TOTAL(v))
	{
		if (FT_VECTOR_GET(v, i) == e)
			return (i);
		++i;
	}
	return (-1);
}
