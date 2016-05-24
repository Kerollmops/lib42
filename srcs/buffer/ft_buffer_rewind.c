/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_rewind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:26:15 by djean             #+#    #+#             */
/*   Updated: 2016/05/19 16:41:00 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

/*
** Recule le buffer de n caractere
** Retourne -1 si n dépasse la len du buffer
** 0 en cas de succès
*/

int	ft_buffer_rewind(t_buffer *b, size_t n)
{
	size_t	nlen;

	if (n > FT_BUFFER_LEN(b))
		return (-1);
	nlen = FT_BUFFER_LEN(b) - n;
	b->str[nlen] = '\0';
	b->len = nlen;
	return ((int)nlen);
}
