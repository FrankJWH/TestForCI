#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main() {

	struct sockaddr_in serv_addr;
	int sock = 0, valread;
	char buffer[1024] = {0};
	const char *hello = "Hello from Client";

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		printf("\nsocket creation failed\n");
		exit(EXIT_FAILURE);
	}

	memset(&serv_addr, '0', sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		printf("\nInvalid address/ Address not supported\n");
		exit(EXIT_FAILURE);
	}

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("\nConnection Failed\n");
		exit(EXIT_FAILURE);
	}

	send(sock, hello, strlen(hello), 0);
	printf("Hello message sent\n");
	valread = read(sock, buffer, 1024);
	printf("%s\n", buffer);

	printf("\nThats it!\n");

	return 0;
}
