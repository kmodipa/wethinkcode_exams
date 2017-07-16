/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 12:36:15 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/10 12:57:16 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(char *str)
{
	char *dup;
	int index;

	index = 0;
	dup = (char *)malloc((sizeof(dup) * ft_strlen(str)) + 1);
	if (dup == NULL)
		return (NULL);
	else
	{
		while (str[index] != '\0')
		{
			dup[index] = str[index];
			index++;
		}
		dup[index] = '\0';
	}
	return (dup);
}

int		main(void)
{
	char *name;
	char *dup;
	int	 index;

	index = 0;
	name = "khomotjo";
	dup = ft_strdup(name);
	while (dup[index] != '\0')
	{
		ft_putchar(dup[index]);
		index++;
	}
	return (0);
}
