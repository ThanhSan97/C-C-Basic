// TCP Client Example in C++
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    const char* hello = "Hello from client";
    char buffer[1024] = {0};

    // 1. Tạo socket (IPv4, TCP)
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 2. Chuyển đổi địa chỉ IP từ text sang binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported" << std::endl;
        return -1;
    }

    // 3. Kết nối tới server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }

    // 4. Gửi dữ liệu đến server
    send(sock, hello, strlen(hello), 0);
    std::cout << "Hello message sent from client" << std::endl;

    // 5. Nhận phản hồi từ server
    int valread = read(sock, buffer, 1024);
    std::cout << "Server: " << buffer << std::endl;

    // 6. Đóng socket
    close(sock);

    return 0;
}
