/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:16 by alilin            #+#    #+#             */
/*   Updated: 2023/07/27 17:18:51 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	l;
	int	i;

	l = ft_strlen(s) - 1;
	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[i]);
	while (l >= 0)
	{
		if (s[l] == c)
			return ((char *)&s[l]);
		l--;
	}
	return (0);
}
