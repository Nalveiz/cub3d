/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:45:47 by musozer           #+#    #+#             */
/*   Updated: 2023/10/30 17:44:09 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*a;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = -1;
	j = 0;
	if (!s || len == 0 || start >= s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			a[j] = s[i];
			j++;
		}
	}
	a[j] = '\0';
	return (a);
}
