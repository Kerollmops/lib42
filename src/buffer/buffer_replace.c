/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/09/14 18:55:39 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Replace the content of the buffer with the string '*s'
*/

t_buffer	*buffer_replace(t_buffer *b, const char *s)
{
	return (buffer_nreplace(b, s, ft_strlen(s)));
}

/*
** Replace the content of the buffer with the string '*s', up to 'len' bytes
*/

t_buffer	*buffer_nreplace(t_buffer *b, const char *s, size_t len)
{
	b->len = 0;
	buffer_ncat(b, s, len);
	b->str[b->len] = '\0';
	return (b);
}
