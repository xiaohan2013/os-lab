#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const* argv[])
{

	int server_fd, new_socket;
	
	if((fd_server = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Socket failed");
		exit(EXIT_FAILURE);
	}

	
	
	
	return 0;
}
