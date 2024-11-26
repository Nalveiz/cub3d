/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:48:42 by musozer           #+#    #+#             */
/*   Updated: 2024/11/25 16:40:40 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	search(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*s;

	if (!s1[0] || !set[0])
		return (ft_strdup(s1));
	first = 0;
	last = ft_strlen(s1) - 1;
	while (first <= last && search(set, s1[first]))
		first++;
	while (first < last && search(set, s1[last]))
		last--;
	if (first > last)
		return (ft_strdup(""));
	s = ft_substr(s1, first, last - first + 1);
	return (s);
}
