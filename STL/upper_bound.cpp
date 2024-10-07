#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    auto it = upper_bound(vec.begin(), vec.end(), 2);
    std::cout << "Upper bound of 3: " << *it << std::endl;
    std::cout << "Found at index: " << (it - vec.begin()) << std::endl;

    return 0;
}