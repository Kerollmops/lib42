#include "array_42.h"

static void	*array_resize(t_array *v)
{
	void	*new;
	size_t	s;

	s = sizeof(void*) * v->max * ARRAY_GROWTH_FACTOR;
	new = ft_realloc(v->data, s, v->total * sizeof(void*));
	if (new == NULL)
		return (NULL);
	v->data = new;
	v->max *= ARRAY_GROWTH_FACTOR;
	return (v);
}

t_array		*array_add(t_array *v, void *e)
{
	if (v->total + 1 >= v->max)
		if (array_resize(v) == NULL)
			return (NULL);
	v->data[v->total++] = e;
	return (v);
}

t_array		*array_insert(t_array *v, size_t i, void *e)
{
	unsigned char	**src;
	size_t			len;

	if (i > v->total)
		return (NULL);
	if (v->total + 1 >= v->max)
		if (array_resize(v) == NULL)
			return (NULL);
	if (i == v->total)
		return (array_add(v, e));
	src = (unsigned char **)(v->data + i);
	len = (v->total - i) * sizeof(void*);
	ft_memmove(src + 1, src, len);
	v->data[i] = e;
	v->total++;
	return (v);
}
