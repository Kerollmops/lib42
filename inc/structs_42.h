/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonhart </var/spool/mail/leonhart>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 11:06:51 by leonhart          #+#    #+#             */
/*   Updated: 2016/06/29 11:10:51 by leonhart         ###   ########.fr       */
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
	size_t	total;
};

#endif
