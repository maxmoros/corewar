/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 20:02:38 by anjansse          #+#    #+#             */
/*   Updated: 2019/03/15 13:39:15 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*s3;

	s3 = ft_strjoin(s1, s2);
	ft_strdel(&s2);
	return (s3);
}
