#ifndef ERROR_42_H
# define ERROR_42_H

# include <unistd.h>
# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "buffer_42.h"

# define FATAL_MALLOC	"fatal: malloc failed !"
# define UNKNOWN_ERROR	"Unknown error !"

void	register_errlist(char *name, t_errors *list, size_t max);
char	*ft_strerror(int errnum);
void	ft_perror(const char *msg);
void	ft_perror_num(const char *msg, int errnum);
void	ft_die(const char *msg);

#endif
