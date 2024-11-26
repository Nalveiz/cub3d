/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musozer <musozer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:41:54 by musozer           #+#    #+#             */
/*   Updated: 2023/10/30 13:14:09 by musozer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len ;
	char			*s1;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (len > i)
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[len] = '\0';
	return (s1);
}
