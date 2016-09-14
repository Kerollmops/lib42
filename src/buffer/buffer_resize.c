/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 18:59:26 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Enlarge the buffer by adding 'expand'
*/

t_buffer	*buffer_resize(t_buffer *b, size_t expand)
{
	void	*new;
	size_t	newsize;

	newsize = b->sizemax * BUFFER_GROWTH_FACTOR;
	while (b->len + expand >= newsize)
		newsize *= BUFFER_GROWTH_FACTOR;
	new = ft_realloc(b->str, newsize, b->sizemax);
	if (new == NULL)
		return (NULL);
	b->sizemax = newsize;
	b->str = new;
	return (b);
}
