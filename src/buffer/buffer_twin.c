/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_twin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:31:05 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

t_buffer	*buffer_twin(t_buffer *b)
{
	t_buffer	*copy;

	copy = buffer_new(b->sizemax);
	if (copy == NULL)
		return (NULL);
	copy->len = b->len;
	ft_memcpy(copy->str, b->str, b->len);
	return (copy);
}
