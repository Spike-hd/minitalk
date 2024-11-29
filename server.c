/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:15:38 by spike             #+#    #+#             */
/*   Updated: 2024/11/29 09:43:51 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_character(char c, char **message, int *len)
{
	if (c == '\0')
	{
		ft_printf("%s\n", *message);
		free(*message);
		*message = NULL;
		*len = 0;
	}
	else
	{
		char *new_message = malloc(*len + 2);
		if (!new_message)
			exit(1);
		if (*message)
		{
			ft_memcpy(new_message, *message, *len);
			free(*message);
		}
		new_message[*len] = c;
		new_message[*len + 1] = '\0';
		*message = new_message;
		(*len)++;
	}
}

void	handle_signal(int signal)
{
	static char	c = 0;
	static int	i = 0;
	static char	*message = NULL;
	static int	len = 0;

	if (signal == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	c |= signal << (7 - i);
	i++;
	if (i == 8)
	{
		i = 0;
		handle_character(c, &message, &len);
		c = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_printf("pid = %d\n", getpid());
	ft_printf("Waiting for signal ...\n");
	while (1)
	{
		pause();
	}
}
