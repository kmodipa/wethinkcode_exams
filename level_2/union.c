/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:23:01 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/10 18:51:31 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_union(char *str1, char * str2)
{
	char sum[ft_strlen(str1) + ft_strlen(str2)];
	int	index;

	index = 0;
	while (str[index] != '\0')
}

int		main(int argc, char **argv)
{
	int	chars;

	chars = 0;
	if (argc < 3)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		ft_union(argv[1], argv[2]);
	}
	return (0);
}
