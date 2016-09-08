/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_strsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 20:14:54 by djean             #+#    #+#             */
/*   Updated: 2016/09/08 10:38:43 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

static void	*free_and_return(t_array *v, char *sub)
{
	void	*p;
	size_t	i;

	i = 0;
	while (i < v->count)
	{
		p = *(void**)TARRAY_GET(v, i);
		free(p);
		++i;
	}
	array_destroy(v);
	free(sub);
	return (NULL);
}

static void	*add_and_return(t_array *v, char *str)
{
	char	*sub;

	sub = ft_strdup(str);
	if (array_add(v, &sub) == NULL)
		return (free_and_return(v, sub));
	return (v);
}

t_array		*array_strsplit(char *str, char c)
{
	t_array		*v;
	char		*sub;
	int			len;

	if ((v = array_new(16, sizeof(char*))) == NULL)
		return (NULL);
	if (c == '\0')
		return (add_and_return(v, str));
	while ((len = ft_strchrpos(str, c)) != -1)
	{
		if ((sub = ft_strsub(str, 0, len)) == NULL)
			return (free_and_return(v, NULL));
		if (array_add(v, &sub) == NULL)
			return (free_and_return(v, sub));
		str += len + 1;
	}
	return (add_and_return(v, str));
}
