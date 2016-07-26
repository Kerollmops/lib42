#include "buffer_42.h"

void	buffer_destroy(t_buffer **b)
{
	free((*b)->str);
	free((*b));
	*b = NULL;
}
