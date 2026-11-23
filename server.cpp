#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int criarScoketIpv4Tcp(){
    return socket(AF_INET, SOCK_STREAM, 0);
}

int main(int argc, char const *argv[])
{

    // criacao do endpoit
    int socketfd = criarScoketIpv4Tcp();
    if(socketfd < 0){
        cout << "Erro ao criar socket." << endl;
        return 1;
    }
    cout << "Scoket criado com sucesso!" << endl;

    // configurando estrutura de endereco do socket
    struct sockaddr_in enderecoSockIpv4Tcp;
    enderecoSockIpv4Tcp.sin_family = AF_INET;
    enderecoSockIpv4Tcp.sin_port = htons(2000);
    enderecoSockIpv4Tcp.sin_addr.s_addr = INADDR_ANY;

    cout << "Endereco do socket configurado" << endl;
    
    return 0;
}
