#include "../../includes/minishell.h"

static void	process(int sig)
{
	if (!kill(g_pid, sig))
	{
		if (sig == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			// g_status = 131;
		}
		else if (sig == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			// g_status = 130;
		}
	}
	else if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		// g_status = 1;
		// g_input = get_input();
	}
}

void		sigint_handler(int sig)
{
	if ((sig == SIGINT || sig == SIGQUIT) && g_pid != 0)
		process(sig);
	else
	{
		if (sig == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			// g_input = get_input();
		}
		else if (sig == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}