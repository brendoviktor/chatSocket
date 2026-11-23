#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char const *argv[])
{
    // criacao do socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd < 0){
        cout << "erro ao criar socket" << endl;
        return 1;
    }
    cout << "Socket criado com sucesso." << endl;

    // configurar endereco do socket
    struct sockaddr_in enderecoServerSockfd;
    enderecoServerSockfd.sin_family = AF_INET;
    enderecoServerSockfd.sin_port = htons(8080);
    const char *ip = "127.0.0.1";
    if(inet_pton(AF_INET, ip, &enderecoServerSockfd.sin_addr)!=1){
        cout << "Erro ao configurar ip ao socket." << endl;
        return 1;
    }else
        cout << "Endereco do servidor configurado com sucesso!" << endl;
    
    // conectando a um servidor 
    int resultadoConnect = connect(socketfd, (struct sockaddr *)&enderecoServerSockfd, sizeof(enderecoServerSockfd));
    if(resultadoConnect < 0){
        cout << "Erro ao conectar ao servidor." << endl;
        close(socketfd);
        return 1;
    }
    cout << "Conectado ao servidor com sucesso!" << endl;
    close(socketfd);


    return 0;
}
