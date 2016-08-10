/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:48 by djean             #+#    #+#             */
/*   Updated: 2016/08/10 16:29:25 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_42_H
# define ERROR_42_H

# include <unistd.h>
# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "buffer_42.h"

# define FATAL_MALLOC	"fatal: malloc failed !"
# define UNKNOWN_ERROR	"Unknown error !"

void	register_errlist(char *name, char **list, size_t max);
char	*ft_strerror(int errnum);
void	ft_perror(const char *msg);
void	ft_perrorn(const char *msg, int errnum);
void	ft_die(const char *msg);
void	fatal_malloc(void);

#endif
