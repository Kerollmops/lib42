#include "array_42.h"

/*
** Alloue un nouveau array et copie la structure *v
** Dans le nouvel espace.
*/

t_array				*array_copy(t_array *v)
{
	t_array	*cp;

	if ((cp = array_new(v->max)) == NULL)
		return (NULL);
	cp->count = v->count;
	ft_memcpy(cp->data, v->data, v->count * sizeof(void*));
	return (cp);
}

static inline void	*free_and_return(t_array *v, char *sub)
{
	free(sub);
	free(v->data);
	free(v);
	return (NULL);
}

t_array				*array_strsplit(char *str, char c)
{
	t_array		*v;
	char		*sub;
	int			len;

	if ((v = array_new(8)) == NULL)
		return (NULL);
	if (c == '\0')
		return (array_add(v, ft_strdup(str)));
	while ((len = ft_strchrpos(str, c)) != -1)
	{
		if ((sub = ft_strsub(str, 0, len)) == NULL)
			return (free_and_return(v, NULL));
		if (array_add(v, sub) == NULL)
			return (free_and_return(v, sub));
		str += len + 1;
	}
	sub = ft_strdup(str);
	if (array_add(v, sub) == NULL)
		return (free_and_return(v, sub));
	return (v);
}
