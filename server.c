/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:15:38 by spike             #+#    #+#             */
/*   Updated: 2024/11/28 14:20:02 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	c |= signal << (7 - i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
			return ;
		else
			ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_printf("__PID: %d\n", getpid());
	ft_printf("Waiting for signal ...\n");
	while (1)
	{
		pause();
	}
}
