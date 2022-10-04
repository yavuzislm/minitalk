/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yislam <yislam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:02:11 by yislam            #+#    #+#             */
/*   Updated: 2022/10/04 20:38:39 by yislam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit_and_shift(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(61);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argv[1][0] == '-' && argv[1][1] == '1' && argv [1][2] == '\0')
	{
		ft_printf("maymun testini geçtiniz.");
		return (0);
	}
	if (argc != 3)
	{
		ft_printf("yanlış girdin kanka");
		return (0);
	}
	ft_bit_and_shift(ft_atoi(argv[1]), argv[2]);
}