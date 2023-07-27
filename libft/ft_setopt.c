/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alilin <alilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:10:52 by alilin            #+#    #+#             */
/*   Updated: 2023/07/27 17:25:14 by alilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_setopt(int nboptions, ...)
{
	int		i;
	va_list	opt;
	char	**options;

	options = (char **)malloc(sizeof(char *) * (nboptions + 1));
	if (!options)
		exit(EXIT_FAILURE);
	va_start(opt, nboptions);
	i = 0;
	while (i < nboptions)
	{
		options[i] = ft_strdup(va_arg(opt, char *));
		i++;
	}
	options[i] = NULL;
	va_end(opt);
	return (options);
}
