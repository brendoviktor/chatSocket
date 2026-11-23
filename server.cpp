#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int criarScoketIpv4Tcp(){
    return socket(AF_INET, SOCK_STREAM, 0);
}

int main(int argc, char const *argv[])
{

    // criacao do endpoit
    int serverSocketfd = criarScoketIpv4Tcp();
    if(serverSocketfd < 0){
        cout << "Erro ao criar socket." << endl;
        return 1;
    }
    cout << "Scoket criado com sucesso!" << endl;

    // configurar estrutura de endereco do socket
    struct sockaddr_in enderecoServerSockIpv4Tcp;
    enderecoServerSockIpv4Tcp.sin_family = AF_INET;
    enderecoServerSockIpv4Tcp.sin_port = htons(8080);
    enderecoServerSockIpv4Tcp.sin_addr.s_addr = INADDR_ANY;

    cout << "Endereco do socket configurado com sucesso!" << endl;

    // associar endereco ao socket
    int resultadobind = bind(serverSocketfd, (struct sockaddr *)&enderecoServerSockIpv4Tcp, sizeof(enderecoServerSockIpv4Tcp));
    if(resultadobind < 0){
        cout << "Erro ao associar endereco ao socket" << endl;
        return 1;
    }
    cout << "Endereco associado ao socket com sucesso!" << endl;

    // colocando o socket em modo de espera por conexoes
    int resultadoListen = listen(serverSocketfd, 10);
    if(resultadoListen < 0){
        cout << "Erro ao aguardar conexoes." << endl;
        return 1;
    }
    cout << "Servidor aguardando conexoes..." << endl;

    // aceitar conexoes
    struct sockaddr_in enderecoClientSocketfd;
    socklen_t tamanhoEstruturaCliente = sizeof(enderecoClientSocketfd);
    int clientSocketfd = accept(serverSocketfd, (struct sockaddr *)&enderecoClientSocketfd, &tamanhoEstruturaCliente);
    if(clientSocketfd < 0){
        cout << "Erro ao aceitar cliente." << endl;
        return 1;
    }
    cout << "Cliente conectado com sucesso!" << endl;

    close(clientSocketfd);
    close(serverSocketfd);
    return 0;
}
