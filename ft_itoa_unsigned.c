/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:14:42 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/07/28 19:08:06 by rmoura-r         ###   ########.fr       */
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
		n = n / 10;
	}
	return (i);
}

static void	write_nbr(char *str, unsigned int n)
{
	unsigned int	nbr;
	int				digit;

	nbr = n;
	digit = 1;
	while (n / 10)
	{
		n = n / 10;
		digit = digit * 10;
	}
	while (digit)
	{
		*str++ = nbr / digit + '0';
		nbr = nbr % digit;
		digit = digit / 10;
	}
	*str = '\0';
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	len = count_chars(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	write_nbr(str, n);
	return (str);
}
