#include "array_42.h"

void	*array_pop(t_array *v)
{
	if (v->total == 0)
		return (NULL);
	return (v->data[--(v->total)]);
}

t_array	*array_push(t_array *v, void *e)
{
	if (v->total == v->max)
		return (NULL);
	v->data[v->total++] = e;
	return (v);
}
