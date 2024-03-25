#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums{1, 2, 4};
  std::cout << *std::lower_bound(nums.begin(), nums.end(), 1) << '\n';
  std::cout << *std::lower_bound(nums.begin(), nums.end(), 2) << '\n';
  std::cout << std::boolalpha <<
    (std::lower_bound(nums.begin(), nums.end(), 5) == nums.end())
    << '\n';
}
