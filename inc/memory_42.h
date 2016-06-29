/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:45:36 by djean             #+#    #+#             */
/*   Updated: 2016/06/29 12:08:25 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_42_H
# define MEMORY_42_H

# include <stdlib.h>
# include <string.h>

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memalloc(size_t size);

#endif
