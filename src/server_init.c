#include "../includes/nm.h"

void usage(char *str)
{
	ft_printf("Usage: %s <port>\n", str);
	exit(-1);
}

void make_server_directory()
{
	char buf[1024];
	int r;
	char *tmp;
	char *aux;

	getcwd(buf, 1023);
	aux = ft_strdup("/server_dir");
	tmp = ft_strjoin((const char *)buf, aux);
	r = mkdir(tmp, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH);
	if (r == 0 && chdir(tmp) == 0)
	{
		free(tmp);
		free(aux);
		return;
	}
	else if (r == -1)
	{
		ft_putendl("An error occurred whilst making a server directory");
		exit(-1);
	}
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
	make_server_directory();
	listen(sock, 42);
	return (sock);
}
