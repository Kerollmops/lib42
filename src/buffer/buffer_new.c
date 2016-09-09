/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/09/09 15:33:07 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

t_buffer	*buffer_new(size_t size)
{
	t_buffer	*new;

	new = ft_memalloc(sizeof(t_buffer));
	if (new == NULL)
		return (NULL);
	return (buffer_init(new, size));
}

t_buffer	*buffer_init(t_buffer *b, size_t size)
{
	size_t	s;

	s = (size == 0) ? BUFFER_INIT_SIZE : size;
	b->sizemax = s;
	b->len = 0;
	b->str = ft_memalloc(sizeof(char) * s);
	if (b->str == NULL)
		return (NULL);
	return (b);
}
