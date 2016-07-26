#include "buffer_42.h"

t_buffer	*buffer_resize(t_buffer *b, size_t len)
{
	void	*new;
	size_t	newsize;

	newsize = b->sizemax * BUFFER_GROWTH_FACTOR;
	while (b->len + len >= newsize)
		newsize *= BUFFER_GROWTH_FACTOR;
	new = ft_realloc(b->str, newsize, b->sizemax);
	if (new == NULL)
		return (NULL);
	b->sizemax = newsize;
	b->str = new;
	return (b);
}
