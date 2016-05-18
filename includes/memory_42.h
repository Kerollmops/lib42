/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:45:36 by djean             #+#    #+#             */
/*   Updated: 2016/05/18 19:02:18 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_42_H
# define MEMORY_42_H

# include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memalloc(size_t size);

#endif
