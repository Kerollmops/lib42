/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 11:36:27 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 13:56:51 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

/*
** free() chaque pointer contenue dans .data
** et reset .total
*/

void	ft_array_clear(t_array *v)
{
	while (v->total > 0)
		free(v->data[--(v->total)]);
}
