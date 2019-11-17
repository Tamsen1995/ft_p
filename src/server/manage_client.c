#include "../../includes/nm.h"

// the buf being the buffer of commands
// this function relays the commands to their appropiate flow
void relay_commands(char *buf, struct s_server_truth *server_truth)
{
	printf(" buf buf :  %s", buf); // TESTING
	if (ft_strcmp(buf, "pwd") == 0)
	{
		printf("\n%d", server_truth->cs);
		ft_putstr(server_truth->server_dir_path);

		// Try to send a message back to the cs, maybe with send ?
		// TESTING
		// int testing;
		// testing = send(server_truth->cs, "testing", 8, MSG_OOB);
		printf("\nbasiiccc - > ");

		// TESTING
	}
}

// cs means connected socket
int manage_client(int cs, struct s_server_truth *server_truth)
{
	int r;
	char buf[1024];

	// save the socket of the individual client here
	server_truth->cs = cs;
	if ((r = recv(cs, buf, 1023, 0)) >= 0)
	{

		buf[r] = '\0';
		if (r > 0)
			relay_commands(buf, server_truth);
		return (42);
	}

	return (4242);
}