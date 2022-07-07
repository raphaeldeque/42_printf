/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 02:33:54 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/06/29 21:33:15 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_c;
	const char	*src_c;

	if (!dst && !src)
		return (dst);
	dst_c = dst;
	src_c = src;
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}
