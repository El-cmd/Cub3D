/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schai <schai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:57:20 by schai             #+#    #+#             */
/*   Updated: 2024/01/02 13:35:55 by schai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/*
	DESCRIPTION :
	The function ft_isprint checks whether c is a printable character or not.

	RETURN VALUE :
	Non-zero if c is printable, zero if not.
*/

int	ft_isprint(int c)
{
	if (c >= 33 && c < 127)
		return (1);
	else
		return (0);
}
