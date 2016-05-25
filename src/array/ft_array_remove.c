/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 12:02:38 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:57:37 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Retire un élément du array et le retourne
*/

void	*ft_array_remove(t_array *v, size_t i)
{
	void	*ptr;

	if (i >= v->total)
		return (NULL);
	ptr = v->data[i];
	while (i < v->total)
	{
		v->data[i] = v->data[i + 1];
		++i;
	}
	v->total -= 1;
	return (ptr);
}
