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

	ft_putendl("chingdao$>1:  ");
	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	ft_putendl("chingdao$>2:  ");
	sin.sin_family = AF_INET;
	ft_putendl("chingdao$>4:  ");
	sin.sin_port = htons(port);
	ft_putendl("chingdao$>3:  ");
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

int main(int ac, char **av)
{
	int port;
	int sock;
	int cs;
	unsigned int cslen;
	struct sockaddr_in csin;
	int r;
	char buf[1024];

	port = 0;
	if (ac != 2)
		usage(av[1]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	ft_putendl("chingdao$>5:  ");
	cs = accept(sock, (struct sockaddr *)&csin, &cslen);
	// RIGHT HERE IS WHERE THE CLIENT CONNECTS
	// SO IDEALLY WE WOULD FORK() HERE
	while ((r = read(cs, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		printf("received %d bytes: [%s]\n", r, buf);
	}
	close(cs);

	close(sock);
	return (0);
}
