/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:03:46 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:31:04 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_memory.h"

/*
** Standard 7.20.3: malloc(0)
** If the size of the space requested is zero,
** the behavior is implementation- deﬁned: either a null pointer is returned,
** or the behavior is as if the size were some nonzero value,
** except that the returned pointer shall not be used to access an object.
*/

void	*ft_memalloc(size_t size)
{
	void	*p;

	if (!size || (p = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}
