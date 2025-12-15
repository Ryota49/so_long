/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemonthi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:07:17 by jemonthi          #+#    #+#             */
/*   Updated: 2025/11/30 14:42:23 by jemonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_error(char *error_msg)
{
	int	len;

	len = 0;
	write (2, "Error\n", 6);
	while (error_msg[len])
		len++;
	write (2, error_msg, len);
	write (2, "\n", 1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

void	display_count_movement(int nbr)
{
	write (1, "Number of movements : ", 22);
	ft_putnbr(nbr);
	write (1, "\n", 1);
}
