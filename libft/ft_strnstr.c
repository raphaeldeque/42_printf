/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:22:12 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/06/29 21:39:58 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*ndl;
	size_t	n;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len)
	{
		hay = (char *)haystack;
		ndl = (char *)needle;
		n = len--;
		while (*hay == *ndl && n--)
		{
			hay++;
			ndl++;
			if (*ndl == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
