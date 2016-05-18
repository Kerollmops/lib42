/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:05:47 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 18:37:58 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_buffer.h"

t_buffer	*ft_buffer_init(t_buffer *b, size_t size)
{
	size_t	s;

	s = (size == 0) ? BUFFER_INIT_SIZE : size;
	b->sizemax = s;
	b->len = 0;
	b->str = malloc(sizeof(char) * s);
	if (b->str == NULL)
		return (NULL);
	return (b);
}
