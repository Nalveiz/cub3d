/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:44:22 by musozer           #+#    #+#             */
/*   Updated: 2023/10/30 17:44:01 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char) c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)(s + i));
	}
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		i--;
		if (s[i] == (char) c)
			return ((char *)s + i);
	}
	return (0);
}
