/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:39:06 by jthor             #+#    #+#             */
/*   Updated: 2021/10/13 18:09:31 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if (c >= 256)
		c -= 256;
	while (*s && *s != c)
	{
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}