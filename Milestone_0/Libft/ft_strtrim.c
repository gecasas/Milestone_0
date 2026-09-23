/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasas <gecasas@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 18:40:06 by gecasas           #+#    #+#             */
/*   Updated: 2026/09/22 17:57:47 by gecasas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}

/*#include <stdio.h>

int main(void)
{
    char const *str = "-++-hola+mundo+---++-";
    char const *set = "+-";
    
	char *res = ft_strtrim(str, set);
    printf("Resultado: '%s'\n", res);
    
    free(res); // Recuerda liberar la memoria reservada con malloc
    return 0;
}
*/