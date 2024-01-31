/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_lib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:29:27 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/31 11:17:20 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_lib(char const *s1, char const *s2)
{
	char			*str;
	size_t			i;
	size_t			j;
	size_t			size;

	i = 0;
	j = 0;
	size = ft_strlen_lib(s1) + ft_strlen_lib(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
