#include "buffer_42.h"

t_buffer	*buffer_new(size_t size)
{
	t_buffer	*new;

	new = ft_memalloc(sizeof(t_buffer));
	if (new == NULL)
		return (NULL);
	return (buffer_init(new, size));
}

t_buffer	*buffer_init(t_buffer *b, size_t size)
{
	size_t	s;

	s = (size == 0) ? BUFFER_INIT_SIZE : size;
	b->sizemax = s;
	b->len = 0;
	b->str = ft_memalloc(sizeof(char) * s);
	if (b->str == NULL)
		return (NULL);
	return (b);
}

t_buffer	*buffer_dup(const char *str)
{
	return (buffer_ndup(str, ft_strlen(str)));
}

t_buffer	*buffer_ndup(const char *str, size_t len)
{
	t_buffer	*new;

	new = buffer_new(len + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new->str, str, len);
	return (new);
}
