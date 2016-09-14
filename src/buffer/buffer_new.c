/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 18:55:04 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Create a new buffer
** The 'size' argument is the initial size for the string
** The allocated string  will be BUFFER_INIT_SIZE at the minimum
** or the next power of 2 if size is bigger than BUFFER_INIT_SIZE
*/

t_buffer	*buffer_new(size_t size)
{
	t_buffer	*new;

	new = ft_memalloc(sizeof(t_buffer));
	if (new == NULL)
		return (NULL);
	return (buffer_init(new, size));
}

/*
** Initialize an already existing buffer
** The rule for the size are the same than for buffer_new
*/

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
