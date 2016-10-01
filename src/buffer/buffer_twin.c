/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_twin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/01 15:14:15 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Return a strict copy of the buffer '*b'
*/

t_buffer	*buffer_twin(t_buffer *b)
{
	t_buffer	*copy;

	copy = buffer_new(b->sizemax - 1);
	if (copy == NULL)
		return (NULL);
	copy->len = b->len;
	copy->iterator = b->iterator;
	ft_memcpy(copy->str, b->str, b->len);
	return (copy);
}
