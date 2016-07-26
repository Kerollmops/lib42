#include "buffer_42.h"

t_buffer	*buffer_replace(t_buffer *b, const char *s)
{
	return (buffer_nreplace(b, s, ft_strlen(s)));
}

t_buffer	*buffer_nreplace(t_buffer *b, const char *s, size_t len)
{
	b->len = 0;
	buffer_ncat(b, s, len);
	b->str[b->len] = '\0';
	return (b);
}
