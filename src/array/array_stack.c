#include "array_42.h"

void	*array_pop(t_array *v)
{
	if (v->count == 0)
		return (NULL);
	return (v->data[--(v->count)]);
}

t_array	*array_push(t_array *v, void *e)
{
	if (v->count == v->max)
		return (NULL);
	v->data[v->count++] = e;
	return (v);
}
