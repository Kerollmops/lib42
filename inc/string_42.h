/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:53:21 by djean             #+#    #+#             */
/*   Updated: 2016/07/26 20:50:54 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_42_H
# define STRING_42_H

# include <stdlib.h>
# include "memory_42.h"

char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t maxlen);
char	*ft_strchr(const char *s, int c);
int		ft_strchrpos(const char *s, int c);
char	*ft_strnchr(const char *s, int c, size_t n);
int		ft_strnchrpos(const char *s, int c, size_t n);
char	*ft_strrchr(const char *s, int c);
int		ft_strrchrpos(const char *s, int c);
char	*ft_strrnchr(const char *s, int c, size_t n);
int		ft_strrnchrpos(const char *s, int c, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strrev(char *str);

#endif
