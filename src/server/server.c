#include "../../includes/nm.h"

void accept_client(int sock, struct s_server_truth *server_truth)
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
			manage_client(cs, server_truth);
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
	struct s_server_truth server_truth;

	port = 0;
	if (ac != 2)
		usage(av[1]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	server_truth.server_dir_path = make_server_directory();
	if (!server_truth.server_dir_path)
	{
		ft_putendl("A dir path could not be created");
		exit(-1);
	}
	accept_client(sock, &server_truth);
	close(sock);
	return (0);
}