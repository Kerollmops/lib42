/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:34:22 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 12:20:04 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib_42.h"

void	*ft_realloc(void *ptr, size_t size, size_t oldsize)
{
	void	*p;

	if (!ptr)
		return (ft_memalloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if ((p = ft_memalloc(size)) == NULL)
		return (NULL);
	ft_memcpy(p, ptr, oldsize);
	free(ptr);
	return (p);
}
