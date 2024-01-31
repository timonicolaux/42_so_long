/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:48:39 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/31 11:17:15 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_lib(const char *s)
{
	char	*str;
	int		i;
	int		size;

	size = ft_strlen_lib(s);
	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < (size + 1))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
