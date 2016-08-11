/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:49 by djean             #+#    #+#             */
/*   Updated: 2016/08/11 12:17:02 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_42_H
# define STRUCTS_42_H

struct	s_buffer
{
	char	*str;
	size_t	len;
	size_t	sizemax;
};

struct	s_array
{
	void	**data;
	size_t	max;
	size_t	count;
	size_t	iterator;
};

#endif
