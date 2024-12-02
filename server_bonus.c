/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <hduflos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:15:38 by spike             #+#    #+#             */
/*   Updated: 2024/12/02 12:51:06 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_character(char c, pid_t client, char **message, int *len)
{
	char	*new_message;

	if (c == '\0')
	{
		ft_printf("%s\n", *message);
		free(*message);
		*message = NULL;
		*len = 0;
		kill(client, SIGUSR1);
	}
	else
	{
		new_message = malloc(*len + 2);
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

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 0;
	static char	*message = NULL;
	static int	len = 0;

	(void)context;
	if (signal == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	c |= signal << (7 - i);
	i++;
	if (i == 8)
	{
		i = 0;
		handle_character(c, info->si_pid, &message, &len);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	ft_printf("pid = %d\n", getpid());
	ft_printf("Waiting for signal ...\n");
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
		{
			ft_printf("sigaction");
			return (1);
		}
		pause();
	}
}
