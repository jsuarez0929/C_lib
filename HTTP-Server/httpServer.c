// Server side C program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080
#define BUFFER_MAX 50000

char* getContent();

int main(int argc, char const *argv[]) {
    int server_fd, new_socket; long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    char *response = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    memset(address.sin_zero, '\0', sizeof address.sin_zero); //fill with 0
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
        {
            perror("In accept");
            exit(EXIT_FAILURE);
        }

        char request[BUFFER_MAX] = {0};
        valread = read(new_socket, request, BUFFER_MAX);
        printf("%s\n", request);
        write(new_socket , response, strlen(response));
        printf("%s\n%s", "Response:", response);
        close(new_socket);
    }
    return 0;
}

char* getContent() {
    static char buffer[BUFFER_MAX] = {0};
    FILE *indexPtr;

    if ((indexPtr = fopen("/content/index.html", "r")) == NULL) {
        printf("%s\n", "Could not locate content");
    }
    else {
        int index = 0;
        while (!feof(indexPtr)) {
            buffer[index] = fgetc(indexPtr);
            index++;
        }
    }

    return buffer;
}
