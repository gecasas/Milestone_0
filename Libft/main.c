/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasas <gecasas@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 12:55:37 by gecasas           #+#    #+#             */
/*   Updated: 2026/09/26 12:55:37 by gecasas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// No incluir en libft

#include "libft.h"

#include <stdio.h>

int main(void)
{
    char    buffer[50];
    char    *str;
    char    **split_arr;
    t_list  *list;
    int     i;

    printf("\n--- CLASIFICACION Y TRANSFORMACION ---\n");
    printf("isalpha('A'): %d | isalpha('1'): %d\n", ft_isalpha('A'), ft_isalpha('1'));
    printf("isdigit('9'): %d | isdigit('x'): %d\n", ft_isdigit('9'), ft_isdigit('x'));
    printf("toupper('m'): %c | tolower('Z'): %c\n", ft_toupper('m'), ft_tolower('Z'));

    printf("\n--- STRINGS BASICAS ---\n");
    printf("strlen(\"42 Malaga\"): %zu\n", ft_strlen("42 Malaga"));
    printf("strncmp(\"abc\", \"abd\", 2): %d\n", ft_strncmp("abc", "abd", 2));
    printf("strchr(\"murcielago\", 'c'): %s\n", ft_strchr("murcielago", 'c'));
    printf("atoi(\"  -4242\"): %d\n", ft_atoi("  -4242"));

    printf("\n--- MEMORIA BURA ---\n");
    ft_bzero(buffer, 50);
    ft_memset(buffer, 'A', 5);
    printf("memset 5x'A': %s\n", buffer);

    printf("\n--- STRINGS MALLOC ---\n");
    str = ft_substr("Escuela 42", 8, 2);
    printf("substr (\"Escuela 42\", 8, 2): %s\n", str);
    free(str);

    str = ft_strjoin("Hola ", "Mundo");
    printf("strjoin (\"Hola \", \"Mundo\"): %s\n", str);
    free(str);

    str = ft_strtrim("---42---", "-");
    printf("strtrim (\"---42---\", \"-\"): %s\n", str);
    free(str);

    str = ft_itoa(-8492);
    printf("itoa (-8492): %s\n", str);
    free(str);

    printf("\n--- SPLIT ---\n");
    split_arr = ft_split("uno,dos,tres", ',');
    i = 0;
    while (split_arr && split_arr[i])
    {
        printf("split[%d]: %s\n", i, split_arr[i]);
        free(split_arr[i]);
        i++;
    }
    free(split_arr);

    printf("\n--- LISTAS ENLAZADAS ---\n");
    list = ft_lstnew(ft_strdup("Nodo Medio"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("Nodo Final")));
    ft_lstadd_front(&list, ft_lstnew(ft_strdup("Nodo Inicio")));
    
    printf("lstsize: %u\n", ft_lstsize(list));
    printf("Primer nodo: %s\n", (char *)list->content);
    printf("Ultimo nodo: %s\n", (char *)ft_lstlast(list)->content);
    
    ft_lstclear(&list, free);

    return (0);
}
