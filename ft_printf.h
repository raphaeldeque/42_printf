/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:31:01 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/07/28 19:06:33 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa_unsigned(unsigned int n);
char	*ft_itoa_hex(unsigned int n, char *base);
char	*ft_itoa_ptr(unsigned long n, char *base);

#endif
