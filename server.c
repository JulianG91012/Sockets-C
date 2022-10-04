#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
	int server_fd, new_socket, val_read; //File descriptor
	struct sockaddr_in address; //Se crea una estructura que almacena la direccion del servidor
	char buffer[1024] = {0}; //Buffer para almacenar los datos que se envian

	//Se usará la tarjeta de Red, con TCP
	server_fd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET; //Se trabaja con la tarjeta de Red
	address.sin_addr.s_addr = INADDR_ANY; //Cualquier direccion IP
	address.sin_port = htons(5000); //Se recibe la conexión por el puerto 5000


	bind(server_fd, (struct sockaddr *)&address, sizeof(address)); //Se enlaza el socket con la direccion del servidor
	listen(server_fd, 1); //El servidor sólo acepta 1 cliente en la queue


	//Se acepta la conexión del cliente, de cualquier dirección IP
	new_socket = accept(server_fd, (struct sockaddr *)NULL, NULL);


	while(1)
	{
		//Se lee el mensaje que envia el cliente
		val_read = read(new_socket, buffer, 1024); 
		printf("%s\n", buffer);
	}

	return 0;

}	


