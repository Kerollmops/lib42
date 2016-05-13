/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:56:52 by djean             #+#    #+#             */
/*   Updated: 2016/05/13 17:11:18 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	ft_vector_print(t_vector *v, void (*print)(void*))
{
	size_t	i;

	i = 0;
	printf("vector->max: %zu\n", v->max);
	printf("vector->total: %zu\n", v->total);
	while (i < v->total)
	{
		if (print == 0)
			printf("vector->data[%d] => %s\n", i, FT_VECTOR_GET(v, i));
		else if (print == (void(*)(void*))1)
			printf("vector->data[%d] => %p\n", i, FT_VECTOR_GET(v, i));
		else
		{
			printf("vector->data[%d] => ", i);
			(*print)(FT_VECTOR_GET(v, i));
		}
		++i;
	}
}
