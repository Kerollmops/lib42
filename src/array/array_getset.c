#include "array_42.h"

void	*array_get(t_array *v, size_t i)
{
	if (i >= v->count)
		return (NULL);
	return (v->data[i]);
}

int		array_indexof(t_array *v, void *e)
{
	size_t	i;

	i = 0;
	while (i < v->count)
	{
		if (v->data[i] == e)
			return (i);
		++i;
	}
	return (-1);
}

/*
** Set le nouvel élément à la place i
** Et retourne l'ancien élément
*/

void	*array_replace(t_array *v, size_t i, void *e)
{
	void	*old;

	if (i >= v->count)
		return (NULL);
	old = v->data[i];
	v->data[i] = e;
	return (old);
}

void	*array_iterator(t_array *v)
{
	static size_t	index = 0;

	if (v == NULL || index == v->count)
	{
		index = 0;
		return (NULL);
	}
	return (v->data[index++]);
}
