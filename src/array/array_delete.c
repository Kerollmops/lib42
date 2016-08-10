/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:31:25 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:31:27 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** Retire un élément et le retourne
*/

void	*array_remove(t_array *v, size_t i)
{
	void	*ret;
	void	**ptr;
	size_t	len;

	if (i >= v->count)
		return (NULL);
	ret = v->data[i];
	ptr = v->data + i;
	len = (v->count - i) * sizeof(void*);
	ft_memmove(ptr, ptr + 1, len);
	v->count -= 1;
	return (ret);
}

void	array_destroy(t_array *v)
{
	free(v->data);
	free(v);
}

/*
** free() chaque pointer
** set .data et .count à 0
*/

void	array_clear(t_array *v)
{
	while (v->count > 0)
		free(v->data[--(v->count)]);
	ft_memset(v->data, 0, v->max * sizeof(void*));
}

void	array_reset(t_array *v)
{
	v->count = 0;
	v->data[0] = NULL;
}
