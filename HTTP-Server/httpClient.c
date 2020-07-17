#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

#define SOCKET_ERROR 0
#define BUFFER_MAX 50000
#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd;
    long response;
    char buffer[BUFFER_MAX] = {0};
    char *http_request = "GET / HTTP/1.1\nHost: localhost:8080\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:72.0) Gecko/20100101 Firefox/72.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8\nAccept-Language: en-US,en;q=0.5\nAccept-Encoding: gzip, deflate\nConnection: keep-alive\n\n";
    struct sockaddr_in address;

    //Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < SOCKET_ERROR) {
        printf("%s\n", "ERROR opening socket");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Socket descriptor created: %d\n", sockfd);
    }

    memset(&address, '0', sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    if (inet_pton(AF_INET, argv[1], &address.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    //Connect
    if(connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("%s\n", "Error establishing connection");
        exit(EXIT_FAILURE);
    }

    send(sockfd, http_request, strlen(http_request), 0);
    response = read(sockfd, buffer, BUFFER_MAX);
    printf("%s\n",buffer);
    return 0;
}
