/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_rewind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/09/26 19:29:20 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Rewind the string by 'n' chars
** Return the new size of the buffer or -1 if the rewind is to large
*/

int	buffer_rewind(t_buffer *b, size_t n)
{
	size_t	nlen;

	if (n > b->len)
		return (-1);
	nlen = b->len - n;
	b->str[nlen] = '\0';
	b->len = nlen;
	return ((int)nlen);
}

/*
** Rewind the string up to 'c' char
** The char 'c' is exclude from the buffer
** Return the number of chars that have been rewind, or -1 if it is not found
*/

int	buffer_rewindchr(t_buffer *b, int c)
{
	int		pos;
	size_t	ret;

	pos = ft_strrchrpos(b->str, c);
	if (pos == -1)
		return (-1);
	b->str[pos] = '\0';
	ret = b->len - (size_t)pos;
	b->len = (size_t)pos;
	return ((int)ret);
}
