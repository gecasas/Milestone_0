/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasas <gecasas@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:40:06 by gecasas           #+#    #+#             */
/*   Updated: 2026/09/21 19:23:45 by gecasas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinstr(char c, char const *set)
{
	int	i;

	while(set[i] != '/0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char*	ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		start;

	i = 0;
	while (s1[i] != '/0')
	{
		if (ft_isinstr(s1[i], set))
			i++;
		
	}
	
}