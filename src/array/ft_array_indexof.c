/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_indexof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:35:33 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:57:14 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

int	ft_array_indexof(t_array *v, void *e)
{
	size_t	i;

	i = 0;
	while (i < FT_ARRAY_TOTAL(v))
	{
		if (FT_ARRAY_GET(v, i) == e)
			return (i);
		++i;
	}
	return (-1);
}
