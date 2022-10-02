#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


int main()
{
    int sock;
    struct sockaddr_in serv_addr;
    char *hello = "Hola, enviando desde el Cliente";
    char buf[128];

    //Se crea el socket del cliente
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);

    //Se "Traduce" la dirección de conexión al servidor desde el localhost
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    //
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 )
    {
        printf("Error en la conexxión");
        return -1;
    }

    // send(sock, hello, strlen(hello), 0);    
    // printf("Mensaje hola enviado \n");
    
    // while(1)
    // {
        //Se lee mensaje escrito y se envía
        //fgets(buf, 128, stdin);
    send(sock, buf, strlen(buf), 0);
    printf("Mensaje Hola enviado \n");
    // }


    return 0;
}