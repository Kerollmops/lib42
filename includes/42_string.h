/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:53:21 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 17:30:25 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include "42_memory.h"

char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_strchrpos(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);

#endif
