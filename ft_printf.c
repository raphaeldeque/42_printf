/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:48:11 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/07/07 18:45:06 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_print(char a, va_list args)
{
	if (a == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (a == 's')
	{
		ft_putstr_fd(va_arg(args, char *), 1);
		return (ft_strlen(va_arg(args, char *)));
	}
	//else if (a == p)  %s, %cdip, 's', 
	// p (unsigned long long?)
	// d  // i
	// u
	// x
	// X
	// %
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
		}
		else
			printf("%c\n", str[i]);
		i++;
	}
	va_end(args);
	return (len);
}


int	main(void)
{
	char	str[] = "abc";
	ft_printf("teste %s", str);
}

