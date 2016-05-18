/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_rewindchr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:52:25 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 18:52:26 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "42_buffer.h"

/*
** Recule le buffer jusqu'au char c
** Retourne le nombre de char reculé
*/

size_t	ft_buffer_rewindchr(t_buffer *b, int c)
{
	int		pos;
	size_t	ret;

	pos = ft_strrchrpos(FT_BUFFER_GET(b), c);
	if (pos == -1)
		return (0);
	b->str[pos] = '\0';
	ret = b->len - pos;
	b->len = pos;
	return (ret);
}
