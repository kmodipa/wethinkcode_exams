/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 13:32:41 by kmodipa           #+#    #+#             */
/*   Updated: 2017/08/03 14:09:39 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int		temp;
	unsigned int		index;

	index = 0;
	while (index < (size - 1))
	{
		if (tab[index] <= tab[index + 1])
			index++;
		else
		{
			temp = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = temp;
			index = 0;
		}
	}
}

int		main(void)
{
	int	tab[5] = {5, 1, 3, 4, 2};
	int index;

	index = 0;
	sort_int_tab(tab, 5);
	while (index < 5)
	{
		printf("%i ", tab[index]);
		index++;
	}
	return (0);
}
