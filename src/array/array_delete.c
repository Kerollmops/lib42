#include "array_42.h"

/*
** Retire un élément et le retourne
*/

void	*array_remove(t_array *v, size_t i)
{
	void	*ret;
	void	**ptr;
	size_t	len;

	if (i >= v->total)
		return (NULL);
	ret = v->data[i];
	ptr = v->data + i;
	len = (v->total - i) * sizeof(void*);
	ft_memmove(ptr, ptr + 1, len);
	v->total -= 1;
	return (ret);
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
