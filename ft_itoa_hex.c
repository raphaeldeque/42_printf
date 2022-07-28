/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:14:42 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/07/28 17:16:27 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_chars(unsigned int n)
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

char	*ft_itoa_hex(unsigned int n, char *base)
{
	char	*str;
	int		len;

	len = count_chars(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[n % 16];
		n = n / 16;
		len--;
	}
	return (str);
}
