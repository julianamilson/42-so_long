/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:08:01 by jmilson-          #+#    #+#             */
/*   Updated: 2021/12/09 21:29:14 by jmilson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define INT_MIN -2147483648
# define BUFFER_SIZE 1
# include <unistd.h>
# include <stdlib.h>

//** Part 1 **

/**
 * @brief Write a function which returns a line read from a file descriptor
 * @param FD File descriptor to read from
 * @return Read line, or null if nothing else to read or an error occurred
 */
char	*get_next_line(int fd);

/**
 * @brief takes a string as an argument and returns its length.
 * @param S source string
 * @param C character to be searched
 */
size_t	ft_strclen(const char *s, char c);

/**
 * @brief converts string to int
 * @param SRC string which is going to be converted
 */
int		ft_atoi(const char *src);

/**
 * @brief adds N 0 bytes to an STR address.
 * @param STR address that is going to receive the 0 bytes
 * @param N amount of 0 bytes to be added
 * @return m
 */
void	ft_bzero(void *str, size_t n);

/**
 * @brief Allocates memory and fills each memory with 0.
 * @param NUMBER amount of memory to be allocated
 * @param SIZE size of the memory to be allocated
 */
void	*ft_calloc(size_t number, size_t size);

/**
 * @brief returns if N is alphanumeric.
 * @param N argument to be checked
 */
int		ft_isalnum(int n);

/**
 * @brief returns if N is from the alphabet.
 * @param N argument to be checked
 */
int		ft_isalpha(int n);

/**
 * @brief returns if N belongs to ASCII.
 * @param N argument to be checked
 */
int		ft_isascii(int n);

/**
 * @brief returns if N is a number.
 * @param N argument to be checked
 */
int		ft_isdigit(int n);

/**
 * @brief returns if N has a printable argument.
 * @param N argument to be checked
 */
int		ft_isprint(int n);

/**
 * @brief looks for the first C on the first N bytes of the memory area pointed.
 * @param N amount of bytes to be checked
 * @param C character to be searched
 * @param STR pointer to the initial memory data
 */
void	*ft_memchr(const void *str, int c, size_t n);

/**
 * @brief compares the first N bytes of two memory areas.
 * @param N amount of bytes to be checked
 * @param STR1 pointer of the first area
 * @param STR2 pointer of the second area
 */
int		ft_memcmp(const void *str1, const void *str2, size_t n);

/**
 * @brief copies the N blocks of memory from SRC to DEST.
 * @param N numbers of bytes to be copied
 * @param SRC pointer of the source data
 * @param DEST pointer to the destiny of data
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief safer than memcpy when it comes to overlapping memory blocks
 * @param N numbers of bytes to move
 * @param SRC pointer of the source data
 * @param DEST pointer to the destiny of data
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief fill memory with a constant byte.
 * @param STR pointer to the block of memory to fill
 * @param C value to be set
 * @param N number of bytes to be set to the value
 */
void	*ft_memset(void *str, int c, size_t n);

/**
 * @brief looks for the first occurrence of C in the string pointed to by STR.
 * @param STR points to the string to be scanned
 * @param C character to be searched
 */
char	*ft_strchr(const char *str, int c);

/**
 * @brief duplicates a string, it copies the STR to a new pointer.
 * @param STR the string to be copied.
 * @return a new address with the same string of str.
 */
char	*ft_strdup(const char *str);

/**
 * @brief returns the size of the concatenation of two strings.
 * @param DEST pointer to the destination area of memory
 * @param SRC pointer to the source area of memory
 * @param DSTSIZE buffer size in bytes
 */
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

/**
 * @brief returns the SRC's lenght, in order to simplify truncation detection.
 * @param DEST destination of the copied bytes
 * @param SRC source string
 * @param SIZE buffer (it can be based on DEST lenght!)
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief takes a string as an argument and returns its length.
 * @param S source string
 */
size_t	ft_strlen(const char *s);

/**
 * @brief compares the first N bytes of two strings.
 * @param STR1 first string
 * @param STR1 second string
 * @param N number of bytes to be compared
 */
int		ft_strncmp(const char *str1, const char *str2, size_t n);

/**
 * @brief looks for the first occurrence of LITTLE inside BIG.
 * @param BIG string that's going to be analised
 * @param LITTLE what we're looking for
 * @param LEN number of bytes from BIG that are going to be analised
 */
char	*ft_strnstr(const char	*big, const char *little, size_t len);

/**
 * @brief returns a pointer to the last occurrence of C in the string.
 * @param STR specifies the pointer to the null terminated string
 * @param C specifies the character to be search for
 */
char	*ft_strrchr(const char *str, int c);

/**
 * @brief turns uppercase into lowercase.
 * @param c argument to be checked
 */
int		ft_tolower(int c);

/**
 * @brief turns lowercase into uppercase.
 * @param c argument to be checked
 */
int		ft_toupper(int c);

//** PART 2 **

/**
 * @brief Allocates and returns a substring from the string ’s’.
 * @param S string from which to create the substring.
 * @param START start index of the substring in the string ’s’.
 * @param LEN The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, result of s1s2's concatenation.
 * @param S1 prefix string
 * @param S2 suffix string
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of 's1' with 'set' trimmed (like hair).
 * @param S1 string to be trimmed.
 * @param SET reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief splitting ’s’ using the character ’c’ as a delimiter.
 * @param S string to be split.
 * @param C delimiter character.
 * @return array of new strings resulting from the split. NULL if it fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief turns int into string.
 * @param N the integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/**
 * @brief Applies ’f’ to each character of the string ’s’ and create new string.
 * @param S string on which to iterate.
 * @param F function to apply to each character.
 * @return  string created from the successive applications of ’f’.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies f to s, index is d first argument.
 * @param S string on which to iterate.
 * @param F function to apply to each character.
 * @return None.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * @param C character to output.
 * @param FD file descriptor on which to write.
 * @return None.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * @param S  The string to output.
 * @param FD file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs string ’s’ to the given file descriptor, followed by newline.
 * @param S string to output.
 * @param FD file descriptor on which to write.
 * @return None.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * @param N integer to output.
 * @param FD file descriptor on which to write.
 * @return None.
 */
void	ft_putnbr_fd(int n, int fd);

#endif
