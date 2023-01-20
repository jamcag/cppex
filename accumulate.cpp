#include <iostream>
#include <numeric>
#include <vector>


int main() {
    const std::vector<int> v{1, 2, 3};
    std::cout << std::accumulate(v.begin(), v.end(), 0) << "\n";
    std::cout << std::accumulate(v.begin(), v.end(), 0, [](auto x, auto y) {
        return x + y;
    }) << "\n";
    

    const std::vector<std::vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // Use std::accumulate to find the row-wise, column-wise, and total sum of a matrix.
    //
    // template< class InputIt, class T, class BinaryOperation >
    // constexpr T accumulate( InputIt first, InputIt last, T init,
    //                         BinaryOperation op );
    std::cout << "Total sum is: " << std::accumulate(mat.begin(), mat.end(), 0, [](auto sum, auto row) {
        return std::accumulate(row.begin(), row.end(), sum);
    }) << "\n";

    const auto rowwise = std::accumulate(mat.begin(), mat.end(), std::vector<int>{}, [](auto sums, auto row) {
        sums.emplace_back(std::accumulate(row.begin(), row.end(), 0));
        return sums;
    });
    std::cout << "Row-wise sums are: ";
    for (const auto sum : rowwise) {
        std::cout << sum << " ";
    }
    std::cout << "\n";

    const auto colwise = std::accumulate(mat.begin(), mat.end(), std::vector<int>{0, 0, 0}, [](auto sums, auto row) {
        sums[0] += row[0];
        sums[1] += row[1];
        sums[2] += row[2];
        return sums;
    });
    std::cout << "Col-wise sums are: ";
    for (const auto sum : colwise) {
        std::cout << sum << " ";
    }
    std::cout << "\n";

}
