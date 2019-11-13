#include "../includes/nm.h"

void usage(char *str)
{
	ft_printf("Usage: %s <port>\n", str);
	exit(-1);
}

int create_server(int port)
{
	int sock;
	struct protoent *proto;
	struct sockaddr_in sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);

	sin.sin_family = AF_INET;

	sin.sin_port = htons(port);

	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	// bind the socket config so to speak to the socket in question
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)))
	{
		ft_putendl("Bind error");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

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

int main(int ac, char **av)
{
	int port;
	int sock;
	int cs;
	unsigned int cslen;
	struct sockaddr_in csin;
	int pid;

	port = 0;
	if (ac != 2)
		usage(av[1]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
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
		wait4(-1, NULL, WNOHANG, NULL);
	}
	// parent process makes pid not 0

	// RIGHT HERE IS WHERE THE CLIENT CONNECTS
	// SO IDEALLY WE WOULD FORK() HERE

	close(cs);

	close(sock);
	return (0);
}
