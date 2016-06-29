/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonhart </var/spool/mail/leonhart>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 10:40:28 by leonhart          #+#    #+#             */
/*   Updated: 2016/06/29 10:41:10 by leonhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_42_H
# define MACROS_42_H

# define FT_ABS(x)			(((x) < 0) ? -(x) : (x))
# define FT_MAX(a, b)		((a) < (b) ? (b) : (a))
# define FT_MIN(a, b)		((a) > (b) ? (b) : (a))
# define FREE(ptr)			(free(ptr), (ptr) = NULL)
# define ARR_SIZ_MAX(a)		(sizeof(a) / sizeof((a)[0]))

#endif
