/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_rewind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:31:05 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Recule le buffer de n caractere
** Retourne -1 si n dépasse la len du buffer
** 0 en cas de succès
*/

int		buffer_rewind(t_buffer *b, size_t n)
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
** Recule le buffer jusqu'au char c
** Retourne le nombre de char reculé
*/

size_t	buffer_rewindchr(t_buffer *b, int c)
{
	int		pos;
	size_t	ret;

	pos = ft_strrchrpos(b->str, c);
	if (pos == -1)
		return (0);
	b->str[pos] = '\0';
	ret = b->len - pos;
	b->len = pos;
	return (ret);
}

size_t	buffer_rewindnchr(t_buffer *b, int c, size_t n)
{
	int		pos;
	size_t	ret;

	pos = ft_strrnchrpos(b->str, c, n);
	if (pos == -1)
		return (0);
	b->str[pos] = '\0';
	ret = b->len - pos;
	b->len = pos;
	return (ret);
}
