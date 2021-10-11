/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <dkoriaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:18:21 by dkoriaki          #+#    #+#             */
/*   Updated: 2021/10/11 15:37:33 by dkoriaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strcmp_type(char *s1, char *s2)
{
	int		len;
	char	*tmp;
	int		i;

	len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (-1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			tmp[i] = str[i] + 32;
		else
			tmp[i] = str[i];
	}
	tmp[i] = '\0'
	i = ft_strcmp(tmp, s2);
	return (i);
}