#include "array_42.h"

/*
** Retire un élément et le retourne
*/

void	*array_remove(t_array *v, size_t i)
{
	void	*ptr;

	if (i >= v->total)
		return (NULL);
	ptr = v->data[i];
	while (i < v->total)
	{
		v->data[i] = v->data[i + 1];
		++i;
	}
	v->total -= 1;
	return (ptr);
}

void	array_destroy(t_array *v)
{
	free(v->data);
	free(v);
}

/*
** free() chaque pointer
** set .data et .total à 0
*/

void	array_clear(t_array *v)
{
	while (v->total > 0)
		free(v->data[--(v->total)]);
	ft_memset(v->data, 0, v->max * sizeof(void*));
}

void	array_reset(t_array *v)
{
	v->total = 0;
	v->data[0] = NULL;
}
