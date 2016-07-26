#include "array_42.h"

t_array	*array_new(size_t size)
{
	t_array	*v;

	v = ft_memalloc(sizeof(t_array));
	if (v == NULL)
		return (NULL);
	if ((array_init(v, size)) == NULL)
	{
		free(v);
		return (NULL);
	}
	return (v);
}

void	*array_init(t_array *v, size_t size)
{
	size_t	s;

	s = (size == 0) ? ARRAY_INIT_CAPACITY : size;
	v->max = s;
	v->total = 0;
	v->data = ft_memalloc(sizeof(void*) * s);
	if (v->data == NULL)
		return (NULL);
	return (v);
}
