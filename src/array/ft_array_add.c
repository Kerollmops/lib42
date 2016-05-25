/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:17:58 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:56:44 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void	*ft_array_add(t_array *v, void *e)
{
	if (v->total + 1 >= v->max - 1)
		if (ft_array_resize(v) == NULL)
			return (NULL);
	v->data[v->total++] = e;
	return (v);
}
