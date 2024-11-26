/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:45:02 by musozer           #+#    #+#             */
/*   Updated: 2023/10/30 17:43:57 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	n = (char *)needle;
	h = (char *)haystack;
	i = 0;
	if (!n[i])
		return (h);
	while (i < len && h[i])
	{
		j = 0;
		while (h[i + j] == n[j] && i + j < len && h[j + i])
		{
			j++;
		}
		if (n[j] == '\0')
			return (&h[i]);
		i++;
	}
	return (0);
}
