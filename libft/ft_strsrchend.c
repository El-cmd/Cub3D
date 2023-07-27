/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsrchend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:15:39 by alilin            #+#    #+#             */
/*   Updated: 2023/07/27 17:36:22 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strsrchend(char *str, char *searched)
{
	size_t	i;
	int		j;

	if (ft_strlen(searched) < ft_strlen(str))
	{
		i = ft_strlen(str) - ft_strlen(searched);
		j = 0;
		while (i < ft_strlen(str))
		{
			if (str[i] != searched[j])
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}
