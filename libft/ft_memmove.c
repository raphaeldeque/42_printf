/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 02:33:54 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/06/29 21:33:55 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_c;
	const char	*src_c;

	if (!dst && !src)
		return (dst);
	dst_c = dst;
	src_c = src;
	if (src_c < dst_c && src_c + len > dst_c)
	{
		dst_c += len;
		src_c += len;
		while (len--)
			*--dst_c = *--src_c;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
