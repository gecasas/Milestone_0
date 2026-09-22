/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasas <gecasas@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:58:16 by gecasas           #+#    #+#             */
/*   Updated: 2026/09/22 19:46:04 by gecasas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	
}

int	ft_countwords(char const *s, char c)
{
	int	words;
	int	new_word;
	int	i;

	new_word = 1;
	words = 0;
	i = 0; 
	while (s[i] != '\0')
	{
		if (s[i] == c)
			new_word = 1;
		else
		{
			if (new_word == 1)
			{
				new_word = 0;
				words++;
			}
		}
		i++;
	}
	return (words);
}
