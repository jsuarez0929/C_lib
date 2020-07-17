### Simple HTTP Web server
HTTP web server written in C that can be deployed remotely or in localhost.

#### Requirements:
- gcc

#### To run:
- First compile the files using gcc
    - Server: `gcc -o server httpServer.c`
    - Client: `gcc -o client httpClient.c` (Optional)
- Run the "server" executable produced by gcc (This must be executed first):
    - `./server`
- To test, you can run the "client" executable compiled in the previous step or test from the browser with the server's IP address.
    - To run the "client" executable, pass server IP address as CLI argument: `./client 127.0.0.1`
