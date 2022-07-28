/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:48:11 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/07/28 19:48:57 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_print1(char a, va_list args)
{
	char	*str;

	if (a == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	if (a == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			str = "(null)";
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	if (a == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	flag_print2(char a, va_list args)
{
	char	*str;
	int		len;

	if (a == 'p')
		str = ft_itoa_ptr(va_arg(args, unsigned long), "0123456789abcdef");
	if (a == 'd' || a == 'i')
		str = ft_itoa(va_arg(args, int));
	if (a == 'u')
		str = ft_itoa_unsigned(va_arg(args, unsigned int));
	if (a == 'x')
		str = ft_itoa_hex(va_arg(args, unsigned int), "0123456789abcdef");
	if (a == 'X')
		str = ft_itoa_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
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
		if (str[i] == '%' && ft_strchr("cs%", str[i + 1]))
		{
			len += flag_print1(str[i + 1], args);
			i++;
		}
		else if (str[i] == '%' && ft_strchr("pdiuxX", str[i + 1]))
		{
			len += flag_print2(str[i + 1], args);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/* #include <stdio.h>

int	main(void)
{
	char	ex[] = "abcd";
	int		i, j;
	
	
	i = ft_printf("%s\n%p\n%c\n%i\n%x\n", ex, ex, 'k', 56, 9199999);
	j = printf("%s\n%p\n%c\n%i\n%x\n", ex, ex, 'k', 56, 9199999);
	printf(" ft_: %i\norig: %i\n", i, j);
} */
