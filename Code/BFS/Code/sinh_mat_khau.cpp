#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> digits;

    // Khởi tạo danh sách số từ 0 đến 9
    for (int i = 0; i <= 9; ++i) {
        digits.push_back(i);
    }

    int count = 0;

    // Sinh tất cả các hoán vị 4 số khác nhau
    // Lặp qua tất cả tổ hợp 4 phần tử khác nhau
    for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
    for (int k = 0; k < 10; ++k)
    for (int l = 0; l < 10; ++l) {
        if (i != j && i != k && i != l &&
            j != k && j != l &&
            k != l) {
            std::cout << i << j << k << l << "\n";
            count++;
        }
    }

    std::cout << "Tổng số hoán vị: " << count << "\n";
    return 0;
}
