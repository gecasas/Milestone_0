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

size_t	ft_countwords(char const *s, char c);
char	*ft_fill_word(char const *s, size_t start, size_t len);

char	**ft_split(char const *s, char c)
{
	//creo doble array que debe devolver
	char		**str;
	size_t		start;
	size_t		len;
	int			new_w;
	size_t			j;

	//cuento el número de palabras que tiene el array
	if (!s)
		return (NULL);

	//reservo memoria para el array de arrays + 1 para NULL
	str = malloc(sizeof (char*) * (ft_countwords(s, c) + 1));
	if (!str)
		return (NULL);

	//lleno cada array con la palabra hasta encontrar caracter delimitador
	start = 0;
	new_w = 1;
	j = 0;
	while (j < ft_countwords(s, c))
	{
		len = 0;
		if (new_w == 1 && s[start] != c)
		{
			while (s[start + len] != c && s[start + len] != '\0')
				len++;
			str[j] = ft_fill_word(s, start, len);
			j++;
			new_w = 0;
		}
		else if (new_w == 0 && s[start] == c)
			new_w = 1;
		start++;
	}
	str[j] = NULL;
	return (str);
}

size_t	ft_countwords(char const *s, char c)
{
	size_t	words;
	int		new_word;
	int		i;

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

char	*ft_fill_word(char const *s, size_t start, size_t len)
{
	char	*str;
	size_t		i;

	str = malloc (sizeof (char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/* void	ft_free(char const *s)
{

} */

#include <stdio.h>

int main(int argc, char **argv)
{
    char    **resultado;
    int     i;
    if (argc == 3)
    {
        printf("Cadena original recibida: %s\n", argv[1]);
        printf("Carácter delimitador: '%c'\n", argv[2][0]);
        printf("----------------------------------\n");
        resultado = ft_split(argv[1], argv[2][0]);
        if (!resultado)
        {
            printf("Error: ft_split devolvió NULL (Fallo de memoria o entrada nula)\n");
            return (1);
        }
        i = 0;
        while (resultado[i] != NULL)
        {
            printf("Array [%d]: %s\n", i, resultado[i]);
            i++;
        }
        printf("Array [%d]: NULL\n", i);
    }
    else
    {
        printf("Error de argumentos.\n");
        printf("Uso correcto: ./a.out \"cadena que quieres dividir\" \"c\"\n");
    }
    return (0);
}
