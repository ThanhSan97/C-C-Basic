#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 3, 8, 6, 2, 7, 10, 1};

    std::nth_element(v.begin(), v.begin() + 3, v.end());

    std::cout << "After nth_element: ";
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Third smallest element: " << v[3] << std::endl;

    return 0;
}
