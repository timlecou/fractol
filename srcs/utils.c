/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoriaki <dkoriaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:18:21 by dkoriaki          #+#    #+#             */
/*   Updated: 2021/10/11 17:00:08 by dkoriaki         ###   ########.fr       */
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

	i = 0;
	len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (-1);
	while (s1[i])
	{
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			tmp[i] = s1[i] + 32;
		else
			tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	i = ft_strcmp(tmp, s2);
	free(tmp);
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	negativ;
	int	nb;
	int	count;

	i = 0;
	negativ = 0;
	nb = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negativ++;
		count++;
		if (count > 1)
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	return ((negativ != 0) ? -nb : nb);
}
