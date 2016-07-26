#include "buffer_42.h"

t_buffer	*buffer_stoa(t_buffer *b, long long value, int base)
{
	char	*n;

	n = ft_stoa_base(value, base);
	buffer_cat(b, n);
	free(n);
	return (b);
}

t_buffer	*buffer_utoa(t_buffer *b, unsigned long long value, int base)
{
	char	*n;

	n = ft_utoa_base(value, base);
	buffer_cat(b, n);
	free(n);
	return (b);
}
