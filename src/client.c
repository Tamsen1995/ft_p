
#include "../includes/nm.h"

// void usage(char *str)
// {
// 	ft_printf("Usage: %s <port>\n", str);
// 	exit(-1);
// }

void usage(char *str)
{
	ft_printf("Usage: %s <port>", str);
	exit(-1);
}

int create_client(char *addr, int port)
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
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl("Connect error");
		exit(2); // TESTING
	}
	return (sock);
}

// void check_for_output_cmd(char *line)
// {
// 	// if ((r = recv(sock, buf, 1023, 0)) > 0)
// 	// {
// 	// 	buf[r] = '\0';
// 	printf("\n-----> LOOK : %s\n", line);
// 	// }
// 	if (ft_strcmp(line, "pwd") == 0)
// 	{
// 		ft_putendl("expect output");
// 	}

// 	// CONTINUER
// }

void check_for_output_cmd(char *line)
{
	size_t r;

	// r = 0;
	// if ((r = recv(sock, buf, 1023, 0)) > 0)
	// {
	// }
	r = 0;
	ft_printf("%s", line);
}

int main(int ac, char **av)
{
	int port;
	int sock;
	char *line;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);

	int r = 0;

	while (42)
	{
		ft_putstr("client_terminal$>:  ");
		r = get_next_line(0, &line);
		write(sock, line, ft_strlen(line));
		check_for_output_cmd(line);
	}
	close(sock);
	return (0);
}
