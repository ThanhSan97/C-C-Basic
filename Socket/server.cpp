// TCP Server Example in C++
#include <iostream>
#include <cstring>  // For memset()
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>  // For close()

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* hello = "Hello from server";

    // 1. Tạo socket (IPv4, TCP)
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket failed" << std::endl;
        return -1;
    }

    // 2. Gán địa chỉ IP và Port cho socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // Chấp nhận kết nối từ bất kỳ IP nào
    address.sin_port = htons(PORT);        // Port chuyển sang dạng network byte order

    // 3. Gắn địa chỉ (bind)
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return -1;
    }

    // 4. Lắng nghe kết nối
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    // 5. Chấp nhận kết nối từ client
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        std::cerr << "Accept failed" << std::endl;
        return -1;
    }

    // 6. Nhận dữ liệu từ client
    int valread = read(new_socket, buffer, 1024);
    std::cout << "Client: " << buffer << std::endl;

    // 7. Gửi phản hồi lại client
    send(new_socket, hello, strlen(hello), 0);
    std::cout << "Hello message sent from server" << std::endl;

    // 8. Đóng kết nối
    close(new_socket);
    close(server_fd);

    return 0;
}
