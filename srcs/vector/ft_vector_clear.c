/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 11:36:27 by djean             #+#    #+#             */
/*   Updated: 2016/05/26 11:20:31 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_42.h"

/*
** free() chaque pointer contenue dans .data
** et reset .total
*/

void	ft_vector_clear(t_vector *v)
{
	while (v->total > 0)
		free(v->data[--(v->total)]);
	ft_bzero(v->data, v->max);
}
