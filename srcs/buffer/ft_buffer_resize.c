/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:21:27 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:04:30 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

t_buffer	*ft_buffer_resize(t_buffer *b, size_t len)
{
	char	*newstr;
	size_t	newsize;

	newsize = sizeof(char) * FT_BUFFER_MAX(b) * BUFFER_GROWTH_FACTOR;
	while (FT_BUFFER_LEN(b) + len >= newsize)
		newsize *= BUFFER_GROWTH_FACTOR;
	newstr = ft_realloc(b->str, newsize, FT_BUFFER_MAX(b));
	if (newstr == NULL)
		return (NULL);
	b->sizemax = newsize;
	b->str = newstr;
	return (b);
}
