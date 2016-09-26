/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/09/26 18:44:27 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Create a new buffer, resulting in the merge of '*b1' and '*b2'
*/

t_buffer	*buffer_merge(t_buffer *b1, t_buffer *b2)
{
	t_buffer	*new;
	size_t		size;

	size = b1->len + b2->len;
	new = buffer_new(size);
	if (new == NULL)
		return (NULL);
	new->len = b1->len + b2->len;
	ft_memcpy(new->str, b1->str, b1->len);
	ft_memcpy(new->str + b1->len, b2->str, b2->len);
	return (new);
}
