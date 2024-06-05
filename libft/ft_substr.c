/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:28:43 by linyao            #+#    #+#             */
/*   Updated: 2024/06/03 15:55:16 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  s_len;
    size_t  sub_len;
    size_t  i;
    char    *sub_str;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    // 如果子字符串起始位置在源字符串的'\0'或之后，返回NULL
    if (start >= s_len)
        return (NULL);
    sub_len = 0;
    // 计算子字符串的长度
    while (s[start + sub_len] && sub_len < len)
        sub_len++;
    sub_str = (char *)malloc((sub_len + 1) * sizeof(char)); // 还要存放字符串结束符
    if (!sub_str)
        return (NULL);
    i = 0;
    while (i < sub_len)
    {
        sub_str[i] = s[start + i];
        i++;
    }
    sub_str[i] = '\0';
    return (sub_str);
}
/*
int main(void)
{
    char const  *s = "Hello World!";
    char        *sub;

    sub = ft_substr(s, 3, 8);
    printf("substring: %s\n", sub);
    return (0);
}
*/
// 在字符串s中寻找返回子字符串，start是子串开始那个字符在s中的索引位置
// len是该子字符串的最大长度