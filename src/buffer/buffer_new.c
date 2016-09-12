/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/09/12 18:30:02 by djean            ###   ########.fr       */
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

	if (size < BUFFER_INIT_SIZE)
		s = BUFFER_INIT_SIZE;
	else if (IS_POWER_OF_2(size))
		s = size;
	else
		s = next_power_of_2(size);
	b->sizemax = s;
	b->len = 0;
	b->str = ft_memalloc(sizeof(char) * s);
	if (b->str == NULL)
		return (NULL);
	return (b);
}
