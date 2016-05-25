/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:00:18 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:57:31 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

t_array	*ft_array_new(size_t size)
{
	t_array	*v;

	v = ft_memalloc(sizeof(t_array));
	if (v == NULL)
		return (NULL);
	if ((ft_array_init(v, size)) == NULL)
	{
		free(v);
		return (NULL);
	}
	return (v);
}
