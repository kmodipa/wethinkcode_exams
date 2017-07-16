/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 13:25:38 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/10 16:16:31 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_arraylen(int *tab)
{
	int index;

	index = 0;
	while (tab[index] != '\0')
		index++;
	return (index);
}

int		max(int* tab, unsigned int len)
{
	int index;
	int check;
	
	index = 0;
	check = tab[index];
	if (ft_arraylen(tab) == 0)
		return (0);
	while (len > 0)
	{
		if (tab[index] > check)
			check = tab[index];
		len--;
		index++;
	}
	printf("%i", check);
	return (check);
}

int 	main(void)
{
	int tab[3] = {2, 9, 7};

	max(tab, 3);
	return (0);
}
