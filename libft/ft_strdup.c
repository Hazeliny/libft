/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:35:45 by linyao            #+#    #+#             */
/*   Updated: 2024/06/13 15:28:49 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = 0;
	i = 0;
	if (!src)
		return (NULL);
	while (src[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
/*
int main(void)
{
    const char  *str = "Hello World!";

    printf("src: %s\n", str);
    printf("dest: %s\n", ft_strdup(str));
    printf("dest1: %s\n", strdup(str));
    return (0);
}
*/
// 该函数复制一个以 null 结尾的字符串，接受一个字符串作为参数
// 并在堆上动态分配足够的内存来存储这个字符串的副本，将原始字符串内容复制到新分配的内存中
// 并返回指向新分配内存的指针。内存分配失败或输入字符串为空，则返回 NULL
