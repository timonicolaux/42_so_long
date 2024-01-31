/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:11:11 by tnicolau          #+#    #+#             */
/*   Updated: 2024/01/31 11:16:59 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_lib(const char *s, int c)
{
	int		i;
	char	*str;
	char	car;

	i = 0;
	car = (char)c;
	str = (char *)s;
	while (str[i] && str[i] != car)
		i++;
	if (str[i] == car)
		return (&str[i]);
	else
		return (0);
}
