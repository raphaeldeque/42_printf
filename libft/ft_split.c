/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoura-r <rmoura-r@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:40:38 by rmoura-r          #+#    #+#             */
/*   Updated: 2022/06/30 19:53:29 by rmoura-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cellcpy(char **res, const char *s, char c)
{
	int	cell;
	int	len;
	int	i;

	cell = 0;
	len = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == c)
			continue ;
		len = 0;
		while (s[i + len] != '\0' && s[i + len] != c)
			len++;
		res[cell] = malloc(sizeof(char) * (len + 1));
		if (!res[cell])
		{
			while (cell >= 0)
				free(res[cell--]);
			return (0);
		}
		ft_strlcpy(res[cell++], &s[i], (len + 1));
		i = i + len - 1;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		cells;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	cells = 0;
	while (s[++i] != '\0')
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
				cells++;
	res = malloc(sizeof(char *) * (cells + 1));
	if (!res)
		return (NULL);
	res[cells] = NULL;
	if (!ft_cellcpy(res, s, c))
		return (NULL);
	return (res);
}
