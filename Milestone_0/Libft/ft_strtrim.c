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

	i = 0;
	while(set[i] != '\0')
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
	int		end;
	int		start;

	if (!s1 || !set)
        return (NULL);
	i = 0;
	start = 0;
	while (s1[start] && ft_isinstr(s1[start], set))
        start++;
	if (s1[start] == '\0')
    {
        str = malloc(1);
        if (str)
            str[0] = '\0';
        return (str);
    }
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_isinstr(s1[end], set))
        end--;
	str = malloc(sizeof (char) * (end - start) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end + 1)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

#include <stdio.h>

int main(void)
{
    char const *str = "-++-hola+mundo+---++-";
    char const *set = "+-";
    
	char *res = ft_strtrim(str, set);
    printf("Resultado: '%s'\n", res);
    
    free(res); // Recuerda liberar la memoria reservada con malloc
    return 0;
}
