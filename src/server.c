#include "../includes/nm.h"

// the buf being the buffer of commands
// this function relays the commands to their appropiate flow
void relay_commands(char *buf)
{
	ft_putstr(buf);
}

// cs means connected socket
void manage_client(int cs)
{
	int r;
	char buf[1024];

	while ((r = recv(cs, buf, 1023, 0)))
	{
		buf[r] = '\0';
		if (r > 0)
			relay_commands(buf);
	}
}

void accept_client(int sock)
{
	int cs;
	unsigned int cslen;
	int pid;
	struct sockaddr_in csin;

	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	pid = fork();
	if (pid == 0)
	{
		// child process makes pid 0
		// in here the server has to manage the client's requests
		while (42)
			manage_client(cs);
	}
	else if (pid != 0)
	{
		// parent process makes pid not 0
		wait4(-1, NULL, WNOHANG, NULL);
	}
	close(cs);
}

int main(int ac, char **av)
{
	int port;
	int sock;

	port = 0;
	if (ac != 2)
		usage(av[1]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	accept_client(sock);
	close(sock);
	return (0);
}
