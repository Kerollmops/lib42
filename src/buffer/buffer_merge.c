#include "buffer_42.h"

t_buffer	*buffer_merge(t_buffer *b1, t_buffer *b2)
{
	t_buffer	*new;
	size_t		size;

	size = b1->sizemax + b2->sizemax;
	new = buffer_new(size);
	if (new == NULL)
		return (NULL);
	new->len = b1->len + b2->len;
	ft_memcpy(new->str, b1->str, b1->len);
	ft_memcpy(new->str + b1->len, b2->str, b2->len);
	return (new);
}
