/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 16:53:21 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 15:04:46 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_strchrpos(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);

#endif
