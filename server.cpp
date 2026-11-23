#include <iostream>
#include <sys/socket.h>

using namespace std;

int criarScoketIpv4Tcp(){
    return socket(AF_INET, SOCK_STREAM, 0);
}

int main(int argc, char const *argv[])
{

    int socketfd = criarScoketIpv4Tcp();
    if(socketfd < 0){
        cout << "Socket criado com sucesso!" << endl;
        return 1;
    }
    
    return 0;
}
