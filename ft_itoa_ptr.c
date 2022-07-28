/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:14:42 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/07/28 19:08:30 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_chars(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

char	*ft_itoa_ptr(unsigned long n, char *base)
{
	char			*str;
	int				len;

	len = count_chars(n) + 2;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "0x", 3);
	str[len] = '\0';
	while (len > 2)
	{
		str[len - 1] = base[n % 16];
		n = n / 16;
		len--;
	}
	return (str);
}
