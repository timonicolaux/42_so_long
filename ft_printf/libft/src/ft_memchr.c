/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:42:34 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/31 11:16:18 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	car;
	size_t			i;

	str = (unsigned char *)s;
	car = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == car)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
