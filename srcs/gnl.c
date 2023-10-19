/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloth <vloth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:58:43 by vloth             #+#    #+#             */
/*   Updated: 2023/10/19 16:07:34 by vloth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*freeee(char *save)
{
	if (save)
	{
		free(save);
		save = NULL;
	}
	return (save);
}

char	*ft_strdupgnl(char *s)
{
	char	*tab;
	size_t	n;

	n = 0;
	tab = malloc(sizeof (char) * ft_strlen(s) + 1);
	if (!tab)
		return (0);
	while (s[n])
	{
		tab[n] = s[n];
		n++;
	}
	tab[n] = 0;
	freeee(s);
	return (tab);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*join;

	if (s2 != 0)
	{
		join = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!join)
			return (0);
		ft_memcpy(join, s1, ft_strlen(s1));
		ft_memcpy(join + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		join[ft_strlen(s1) + ft_strlen(s2)] = 0;
		free(s1);
		s1 = NULL;
		return (join);
	}
	return (s1);
}

char	**get_next_line(int fd)
{
	static char	*save;
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	char		*line;

	ret = 1;
	if (fd > 1024 || fd < 0 || BUFFER_SIZE < 0 || ret < 0)
		return (NULL);
	while (ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = 0;
		if (ret < 0)
			return (NULL);
		save = ft_strjoingnl(save, buff);
	}
	line = ft_strdupgnl(save);
	return (ft_split(line, '\n'));
}