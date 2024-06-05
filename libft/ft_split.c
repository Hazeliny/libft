/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:41:40 by linyao            #+#    #+#             */
/*   Updated: 2024/06/04 21:03:42 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

// 计算要分割的子字符串substrings的个数
static size_t   ft_subCount(char const  *s, char c)
{
    size_t  i;
    size_t  num;

    if (!s)
        return (0);
    i = 0;
    while (s[i] == c)
    {
        num = 0;
        i++;
    }
    if (s[i] != c && s[i] != '\0')
        num = 1;
    while (s[i])
    {
        if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
            num += 1;
        i++;
    }
    return (num);
}

// 计算具体的子字符串中的字符个数
static size_t   ft_subLen(char const *s, size_t i, char c)
{
    size_t  len;

    len = 0;
    while (s[i] && s[i] != c)
    {
        len++;
        i++;
    }
    return (len);
}

char    **ft_split(char const *s, char c)
{
    char    **array;
    size_t  array_index; // 数组元素的索引
    size_t  sub_len; // 子字符串长度
    size_t  i;

    array = (char **)ft_calloc((ft_subCount(s, c) + 1), sizeof(char *));
    if (!s || !array)
        return (NULL);
    i = 0;
    array_index = 0;
    while (array_index < ft_subCount(s, c))
    {
        while (s[i] == c)
            i++;
        sub_len = ft_subLen(s, i, c);
        array[array_index] = ft_substr(s, i, sub_len);
        i += sub_len;
        array_index++;
    }
    return (array);
}

/*
int main(void)
{
    char const  *s = "aaaxyza782a9e";
    char        c = 'a';
    size_t      j = 0;
    
    printf("%zu\n", ft_subCount(s, c));
    printf("%zu\n", ft_subLen(s, 11, c));
    while (j < ft_subCount(s, c))
    {
        printf("%s\n", ft_split(s, c)[j]);
        j++;
    }
    return (0);
}
*/