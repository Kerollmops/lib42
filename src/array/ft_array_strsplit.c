/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_strsplit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 14:50:31 by djean             #+#    #+#             */
/*   Updated: 2016/05/25 18:01:11 by adubois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

static inline void	*free_and_return(t_array *v, char *sub)
{
	free(sub);
	ft_array_destroy(v);
	return (NULL);
}

t_array				*ft_array_strsplit(char *str, char c)
{
	t_array		*v;
	char		*sub;
	int			len;

	if ((v = ft_array_new(8)) == NULL)
		return (NULL);
	if (c == '\0')
		return (ft_array_add(v, ft_strdup(str)));
	while ((len = ft_strchrpos(str, c)) != -1)
	{
		if ((sub = ft_strsub(str, 0, len)) == NULL)
			return (free_and_return(v, NULL));
		if (ft_array_add(v, sub) == NULL)
			return (free_and_return(v, sub));
		str += len + 1;
	}
	sub = ft_strdup(str);
	if (ft_array_add(v, sub) == NULL)
		return (free_and_return(v, sub));
	return (v);
}
