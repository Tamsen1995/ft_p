#include "../../includes/nm.h"

// the buf being the buffer of commands
// this function relays the commands to their appropiate flow
void relay_commands(char *buf, struct s_server_truth *server_truth)
{

	if (ft_strcmp(buf, "pwd") == 0)
	{
		ft_putstr(server_truth->server_dir_path);
		// CONTINUER
	}
}

// cs means connected socket
void manage_client(int cs, struct s_server_truth *server_truth)
{
	int r;
	char buf[1024];

	while ((r = recv(cs, buf, 1023, 0)))
	{
		buf[r] = '\0';
		if (r > 0)
			relay_commands(buf, server_truth);
	}
}