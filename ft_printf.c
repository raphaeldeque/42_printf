/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:48:11 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/07/07 21:34:45 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_print(char a, va_list args)
{
	//va_list	argcpy;
	char	*str;
	
	if (a == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (a == 's')
	{
		str = va_arg(args, char *);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	//else if (a == p)
	// p (unsigned long long?)
	else if (a == 'i' || a == 'd')
	{
		str = ft_itoa(va_arg(args, int));
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	// u
	// x
	// X
	else if (a == '%')
		ft_putchar_fd(a, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += flag_print(str[i + 1], args);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}


#include <stdio.h>
int	main(void)
{
	char	ex[] = "abc";
	int		i;
	
	i = ft_printf("%s\n%c\n%i\n%d", ex, 'k', 56, 999);
	printf("\noutput: %i\n", i);
}

