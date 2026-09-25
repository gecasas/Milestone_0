*Este proyecto ha sido creado como parte del currículo de 42 por gecasas.*

# Libft

My first C library, built from scratch as part of the 42 curriculum.

<details>
<summary><strong>English</strong></summary>

## Introduction

Libft is my first library project at 42. I built a reusable collection of C functions from scratch, recreating selected functions from the standard C library and implementing additional utilities for strings, memory management, file descriptors and linked lists.

The main goal of the project was not only to obtain a working library, but to develop a solid understanding of fundamental C concepts that I will rely on throughout the rest of the 42 cursus.

The resulting library is compiled into a static archive named `libft.a` and can be reused in future C projects.

---

## Objectives

Through this project, I worked extensively with:

* Pointers and pointer arithmetic
* Strings and character arrays
* Dynamic memory allocation
* Memory manipulation
* Function pointers
* Structures
* Linked lists
* Static libraries
* Makefiles
* Compilation and linking
* Error handling and edge cases
* Memory management
* Code organization and the 42 coding standard

I designed the library to be reusable throughout future projects where its functions are allowed.

---

## Function Reference

| Category        | Function          | Description                                                          |
| --------------- | ----------------- | -------------------------------------------------------------------- |
| Character       | `ft_isalpha`      | Checks whether a character is alphabetic.                            |
| Character       | `ft_isdigit`      | Checks whether a character is a decimal digit.                       |
| Character       | `ft_isalnum`      | Checks whether a character is alphanumeric.                          |
| Character       | `ft_isascii`      | Checks whether a character belongs to the ASCII range.               |
| Character       | `ft_isprint`      | Checks whether a character is printable.                             |
| Character       | `ft_toupper`      | Converts a lowercase character to uppercase.                         |
| Character       | `ft_tolower`      | Converts an uppercase character to lowercase.                        |
| String          | `ft_strlen`       | Returns the length of a null-terminated string.                      |
| String          | `ft_strchr`       | Locates the first occurrence of a character in a string.             |
| String          | `ft_strrchr`      | Locates the last occurrence of a character in a string.              |
| String          | `ft_strncmp`      | Compares two strings up to a specified number of characters.         |
| String          | `ft_strnstr`      | Searches for a substring within a string up to a specified length.   |
| String          | `ft_strlcpy`      | Copies a string into a destination buffer with size limitation.      |
| String          | `ft_strlcat`      | Appends a string to another with size limitation.                    |
| String          | `ft_strdup`       | Creates a dynamically allocated duplicate of a string.               |
| String          | `ft_substr`       | Creates a dynamically allocated substring.                           |
| String          | `ft_strjoin`      | Creates a new string by concatenating two strings.                   |
| String          | `ft_strtrim`      | Removes specified characters from the beginning and end of a string. |
| String          | `ft_split`        | Splits a string into an array of strings using a delimiter.          |
| String          | `ft_strmapi`      | Creates a new string by applying a function to each character.       |
| String          | `ft_striteri`     | Applies a function to each character of a string in place.           |
| Memory          | `ft_memset`       | Fills a memory area with a specified byte value.                     |
| Memory          | `ft_bzero`        | Sets a memory area to zero.                                          |
| Memory          | `ft_memcpy`       | Copies a block of memory to another memory area.                     |
| Memory          | `ft_memmove`      | Copies memory while safely handling overlapping areas.               |
| Memory          | `ft_memchr`       | Searches for a byte within a memory area.                            |
| Memory          | `ft_memcmp`       | Compares two memory areas byte by byte.                              |
| Memory          | `ft_calloc`       | Allocates and initializes a zeroed memory block.                     |
| Conversion      | `ft_atoi`         | Converts the initial numeric portion of a string into an integer.    |
| Conversion      | `ft_itoa`         | Converts an integer into a dynamically allocated string.             |
| File descriptor | `ft_putchar_fd`   | Writes a character to a file descriptor.                             |
| File descriptor | `ft_putstr_fd`    | Writes a string to a file descriptor.                                |
| File descriptor | `ft_putendl_fd`   | Writes a string followed by a newline to a file descriptor.          |
| File descriptor | `ft_putnbr_fd`    | Writes an integer to a file descriptor.                              |
| Linked list     | `ft_lstnew`       | Creates and initializes a new list node.                             |
| Linked list     | `ft_lstadd_front` | Adds a node to the beginning of a list.                              |
| Linked list     | `ft_lstsize`      | Returns the number of nodes in a list.                               |
| Linked list     | `ft_lstlast`      | Returns the last node of a list.                                     |
| Linked list     | `ft_lstadd_back`  | Adds a node to the end of a list.                                    |
| Linked list     | `ft_lstdelone`    | Deletes a node and frees its content using a provided function.      |
| Linked list     | `ft_lstclear`     | Deletes and frees an entire list.                                    |
| Linked list     | `ft_lstiter`      | Applies a function to every node in a list.                          |
| Linked list     | `ft_lstmap`       | Creates a new list by applying a function to every node.             |

---

## Linked Lists

I implemented the linked-list functionality using the following structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list    *next;
}                   t_list;
```

Using `void *` for `content` allows the list to store different types of data without coupling the structure to a specific type.

The library provides functions covering the complete basic lifecycle of a singly linked list:

* Creating nodes
* Adding nodes to the front or back
* Measuring list size
* Accessing the last node
* Deleting individual nodes
* Clearing complete lists
* Iterating through nodes
* Creating transformed lists

Linked lists were the part of the project that required the most attention from me, especially `ft_lstmap`, where list construction, function pointers and memory management have to work together correctly.

---

## Project Structure

I kept all project files in the repository root, following the project requirements.

```text
libft/
├── Makefile
├── libft.h
├── ft_*.c
└── libft.a
```

`libft.h` contains the `t_list` structure and the declarations of all public functions.

I use `static` helper functions when a function is only required internally by a specific implementation. This keeps their scope limited to the corresponding source file.

---

## Compilation

I use the included Makefile to build the static library.

### Build

```bash
make
```

This generates:

```text
libft.a
```

in the project root.

### Available targets

```bash
make
make all
make clean
make fclean
make re
```

| Target        | Description                         |
| ------------- | ----------------------------------- |
| `make`        | Builds `libft.a`.                   |
| `make all`    | Builds `libft.a`.                   |
| `make clean`  | Removes object files.               |
| `make fclean` | Removes object files and `libft.a`. |
| `make re`     | Performs a complete rebuild.        |

I compile the source files using:

```text
-Wall -Wextra -Werror
```

and create the static library using `ar`.

---

## Using Libft

Once I have built `libft.a`, I can link it to another C project.

For example:

```bash
cc main.c -L. -lft -o program
```

and include the library header:

```c
#include "libft.h"
```

I can then reuse the library in future 42 projects where its functions are permitted.

---

## Quality & Validation

I validated the project using:

* **Norminette**
* **sfabi**
* **Tripouille's 42 tester**

I also used small personal `main` programs during development to isolate and verify individual functions when necessary.

The testing process covers a wide range of normal and edge cases. Memory management was also checked through the testing tools, and the project has no detected memory leaks.

---

## Memory Management

Memory management is an important part of my implementation, particularly for functions that dynamically allocate memory.

These include:

```text
ft_calloc
ft_strdup
ft_substr
ft_strjoin
ft_strtrim
ft_split
ft_itoa
ft_strmapi
```

I paid particular attention to:

* Correct allocation sizes
* Allocation failures
* Ownership of dynamically allocated memory
* Complete cleanup when an operation fails
* Avoiding memory leaks
* Avoiding invalid memory accesses
* Avoiding double frees

This becomes especially relevant in `ft_split` and the linked-list functions, where several allocations can be involved in a single operation.

---

## What I Learned

Libft gave me practical experience with many of the fundamental concepts I will use throughout my C projects at 42.

In particular, I strengthened my understanding of:

* Pointers
* Dynamic memory management
* String manipulation
* Function pointers
* Structures
* Linked lists
* Static libraries
* Makefiles
* Compilation and linking
* Debugging
* Testing
* Edge cases
* Working under strict coding constraints

The project also helped me understand how relatively simple low-level operations can be combined to build reusable abstractions.

---

## AI Usage

I used AI primarily as a **learning and debugging tool**.

My use of AI focused on:

* Understanding the behaviour and purpose of specific C functions
* Clarifying concepts related to linked lists
* Resolving questions about particular implementation details
* Reviewing isolated errors
* Understanding specific edge cases
* Reinforcing concepts after attempting the implementation myself

I did **not** use AI to generate the project's code.

**100% of the project code was written by me.**

I used AI to support my understanding and occasionally help me locate the source of a specific problem, while keeping the implementation itself under my control.

This distinction was particularly important to me in Libft because the purpose of the project is to build the C fundamentals required for the following projects in the 42 cursus.

---

## Resources

Throughout the project, I relied mainly on:

* The official **42 Libft subject**
* C standard-library documentation
* Unix/Linux manual pages (`man`)
* Compiler documentation
* Testing tools
* Small personal test programs

The official project subject was my primary reference for the required behaviour, restrictions and function interfaces.

---

## Author

**gecasas**

42 Málaga

[GitHub](https://github.com/gecasas)

</details>

<details>
<summary><strong>Español</strong></summary>

## Introducción

Libft es mi primer proyecto de biblioteca en 42. He construido desde cero una colección reutilizable de funciones en C, recreando determinadas funciones de la biblioteca estándar y desarrollando utilidades adicionales para trabajar con strings, gestión de memoria, descriptores de archivo y listas enlazadas.

El objetivo principal del proyecto no ha sido únicamente conseguir una biblioteca funcional, sino desarrollar una base sólida de conocimientos de C que pueda utilizar durante el resto del cursus de 42.

El resultado es una biblioteca estática llamada `libft.a`, preparada para ser reutilizada en futuros proyectos de C.

---

## Objetivos

Durante el proyecto he trabajado especialmente con:

* Punteros y aritmética de punteros
* Strings y arrays de caracteres
* Reserva dinámica de memoria
* Manipulación de memoria
* Punteros a funciones
* Estructuras
* Listas enlazadas
* Bibliotecas estáticas
* Makefiles
* Compilación y linking
* Gestión de errores y casos límite
* Gestión de memoria
* Organización del código y Norma de 42

He diseñado la biblioteca para poder reutilizarla en futuros proyectos en los que sus funciones estén permitidas.

---

## Referencia de funciones

| Categoría       | Función           | Descripción                                                                 |
| --------------- | ----------------- | --------------------------------------------------------------------------- |
| Caracteres      | `ft_isalpha`      | Comprueba si un carácter es alfabético.                                     |
| Caracteres      | `ft_isdigit`      | Comprueba si un carácter es un dígito decimal.                              |
| Caracteres      | `ft_isalnum`      | Comprueba si un carácter es alfanumérico.                                   |
| Caracteres      | `ft_isascii`      | Comprueba si un carácter pertenece al rango ASCII.                          |
| Caracteres      | `ft_isprint`      | Comprueba si un carácter es imprimible.                                     |
| Caracteres      | `ft_toupper`      | Convierte un carácter minúscula a mayúscula.                                |
| Caracteres      | `ft_tolower`      | Convierte un carácter mayúscula a minúscula.                                |
| Strings         | `ft_strlen`       | Devuelve la longitud de un string terminado en `\0`.                        |
| Strings         | `ft_strchr`       | Busca la primera aparición de un carácter en un string.                     |
| Strings         | `ft_strrchr`      | Busca la última aparición de un carácter en un string.                      |
| Strings         | `ft_strncmp`      | Compara dos strings hasta un número determinado de caracteres.              |
| Strings         | `ft_strnstr`      | Busca un substring dentro de un string hasta una longitud determinada.      |
| Strings         | `ft_strlcpy`      | Copia un string limitando el tamaño del buffer destino.                     |
| Strings         | `ft_strlcat`      | Concatena un string limitando el tamaño total del buffer.                   |
| Strings         | `ft_strdup`       | Crea una copia dinámica de un string.                                       |
| Strings         | `ft_substr`       | Crea dinámicamente un substring.                                            |
| Strings         | `ft_strjoin`      | Crea un nuevo string concatenando dos strings.                              |
| Strings         | `ft_strtrim`      | Elimina determinados caracteres al principio y al final de un string.       |
| Strings         | `ft_split`        | Divide un string en un array de strings utilizando un delimitador.          |
| Strings         | `ft_strmapi`      | Crea un nuevo string aplicando una función a cada carácter.                 |
| Strings         | `ft_striteri`     | Aplica una función a cada carácter de un string modificándolo directamente. |
| Memoria         | `ft_memset`       | Rellena una zona de memoria con un valor determinado.                       |
| Memoria         | `ft_bzero`        | Establece a cero una zona de memoria.                                       |
| Memoria         | `ft_memcpy`       | Copia un bloque de memoria a otra zona.                                     |
| Memoria         | `ft_memmove`      | Copia memoria gestionando correctamente zonas solapadas.                    |
| Memoria         | `ft_memchr`       | Busca un byte dentro de una zona de memoria.                                |
| Memoria         | `ft_memcmp`       | Compara dos zonas de memoria byte a byte.                                   |
| Memoria         | `ft_calloc`       | Reserva memoria e inicializa todos sus bytes a cero.                        |
| Conversión      | `ft_atoi`         | Convierte la parte numérica inicial de un string a un entero.               |
| Conversión      | `ft_itoa`         | Convierte un entero en un string reservado dinámicamente.                   |
| File descriptor | `ft_putchar_fd`   | Escribe un carácter en un descriptor de archivo.                            |
| File descriptor | `ft_putstr_fd`    | Escribe un string en un descriptor de archivo.                              |
| File descriptor | `ft_putendl_fd`   | Escribe un string seguido de un salto de línea.                             |
| File descriptor | `ft_putnbr_fd`    | Escribe un entero en un descriptor de archivo.                              |
| Lista enlazada  | `ft_lstnew`       | Crea e inicializa un nuevo nodo.                                            |
| Lista enlazada  | `ft_lstadd_front` | Añade un nodo al principio de una lista.                                    |
| Lista enlazada  | `ft_lstsize`      | Devuelve el número de nodos de una lista.                                   |
| Lista enlazada  | `ft_lstlast`      | Devuelve el último nodo de una lista.                                       |
| Lista enlazada  | `ft_lstadd_back`  | Añade un nodo al final de una lista.                                        |
| Lista enlazada  | `ft_lstdelone`    | Elimina un nodo y libera su contenido mediante una función dada.            |
| Lista enlazada  | `ft_lstclear`     | Elimina y libera una lista completa.                                        |
| Lista enlazada  | `ft_lstiter`      | Aplica una función al contenido de cada nodo.                               |
| Lista enlazada  | `ft_lstmap`       | Crea una nueva lista aplicando una función a cada nodo.                     |

---

## Listas enlazadas

He implementado la funcionalidad de listas enlazadas utilizando la siguiente estructura:

```c
typedef struct s_list
{
    void            *content;
    struct s_list    *next;
}                   t_list;
```

El uso de `void *` en `content` permite almacenar diferentes tipos de datos sin asociar la estructura a un tipo concreto.

Las funciones implementadas cubren las operaciones básicas necesarias para trabajar con una lista enlazada:

* Crear nodos
* Añadir nodos al principio o al final
* Obtener el tamaño de una lista
* Obtener el último nodo
* Eliminar nodos individuales
* Liberar listas completas
* Iterar sobre los nodos
* Crear nuevas listas mediante transformaciones

Las listas enlazadas fueron la parte del proyecto que más atención me requirió, especialmente `ft_lstmap`, donde hay que combinar correctamente la creación de listas, los punteros a funciones y la gestión de memoria.

---

## Estructura del proyecto

He mantenido todos los archivos en la raíz del repositorio, siguiendo los requisitos del proyecto.

```text
libft/
├── Makefile
├── libft.h
├── ft_*.c
└── libft.a
```

`libft.h` contiene la estructura `t_list` y las declaraciones de todas las funciones públicas.

Utilizo funciones auxiliares `static` cuando solo son necesarias internamente para una implementación concreta, limitando así su ámbito al archivo correspondiente.

---

## Compilación

Utilizo el Makefile incluido para construir la biblioteca estática.

### Compilar

```bash
make
```

Esto genera:

```text
libft.a
```

en la raíz del proyecto.

### Targets disponibles

```bash
make
make all
make clean
make fclean
make re
```

| Target        | Descripción                              |
| ------------- | ---------------------------------------- |
| `make`        | Compila `libft.a`.                       |
| `make all`    | Compila `libft.a`.                       |
| `make clean`  | Elimina los archivos objeto.             |
| `make fclean` | Elimina los archivos objeto y `libft.a`. |
| `make re`     | Realiza una recompilación completa.      |

Compilo los archivos utilizando:

```text
-Wall -Wextra -Werror
```

y genero la biblioteca estática mediante `ar`.

---

## Uso de Libft

Una vez compilada `libft.a`, puedo enlazarla con otro proyecto de C.

Por ejemplo:

```bash
cc main.c -L. -lft -o program
```

e incluir el header:

```c
#include "libft.h"
```

De esta forma puedo reutilizar la biblioteca en futuros proyectos de 42 en los que sus funciones estén permitidas.

---

## Calidad y validación

He validado el proyecto utilizando:

* **Norminette**
* **sfabi**
* **Tripouille's 42 tester**

Durante el desarrollo también utilicé pequeños programas `main` para comprobar funciones concretas de forma aislada cuando fue necesario.

Los tests cubren una amplia variedad de casos normales y casos límite. También he comprobado la gestión de memoria mediante las herramientas de testing y no se han detectado memory leaks.

---

## Gestión de memoria

La gestión de memoria es una parte importante de mi implementación, especialmente en las funciones que realizan reservas dinámicas.

Entre ellas se encuentran:

```text
ft_calloc
ft_strdup
ft_substr
ft_strjoin
ft_strtrim
ft_split
ft_itoa
ft_strmapi
```

He prestado especial atención a:

* Tamaños correctos de las reservas
* Fallos de `malloc`
* Propiedad de la memoria reservada
* Liberación completa cuando una operación falla
* Evitar memory leaks
* Evitar accesos inválidos
* Evitar dobles liberaciones

Esto resulta especialmente importante en `ft_split` y en las funciones de listas enlazadas, donde una sola operación puede implicar varias reservas de memoria.

---

## Qué he aprendido

Libft me ha permitido trabajar de forma práctica muchos de los conceptos fundamentales de C que utilizaré durante el resto de mis proyectos en 42.

En particular, he reforzado mis conocimientos sobre:

* Punteros
* Gestión dinámica de memoria
* Manipulación de strings
* Punteros a funciones
* Estructuras
* Listas enlazadas
* Bibliotecas estáticas
* Makefiles
* Compilación y linking
* Debugging
* Testing
* Casos límite
* Trabajo bajo restricciones estrictas de programación

El proyecto también me ha ayudado a entender cómo combinar operaciones de bajo nivel relativamente sencillas para construir herramientas reutilizables.

---

## Uso de IA

He utilizado herramientas de IA principalmente como **apoyo didáctico y de debugging**.

Mi uso se ha centrado en:

* Comprender el funcionamiento de determinadas funciones de C
* Resolver dudas relacionadas con las listas enlazadas
* Aclarar conceptos concretos
* Revisar errores aislados
* Comprender determinados casos límite
* Reforzar conceptos después de intentar resolverlos por mi cuenta

No he utilizado IA para generar el código del proyecto.

**El 100 % del código del proyecto ha sido escrito por mí.**

He utilizado la IA como apoyo para comprender conceptos y, en ocasiones, localizar el origen de un problema concreto, manteniendo bajo mi control la implementación del proyecto.

Esta distinción ha sido especialmente importante para mí en Libft, ya que uno de los objetivos principales del proyecto es desarrollar los fundamentos de C necesarios para los siguientes proyectos del cursus de 42.

---

## Recursos

Durante el proyecto he utilizado principalmente:

* El **subject oficial de Libft**
* Documentación de la biblioteca estándar de C
* Manuales de Unix/Linux (`man`)
* Documentación del compilador
* Herramientas de testing
* Pequeños programas propios para realizar pruebas

El subject oficial ha sido mi referencia principal para el comportamiento requerido, las restricciones y las interfaces de las funciones.

---

## Autor

**gecasas**

42 Málaga

[GitHub](https://github.com/gecasas)

</details>
