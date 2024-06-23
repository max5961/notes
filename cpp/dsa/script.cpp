#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
  public:
    int singleNumber(std::vector<int> &nums) {
        std::unordered_set<int> copy;
        std::unordered_set<int> dups;

        for (int num : nums) {
            if (copy.find(num) != copy.end()) {
                dups.insert(num);
            }

            copy.insert(num);
        }

        for (int num : nums) {
            if (dups.find(num) == dups.end()) {
                return num;
            }
        }

        return 0;
    }
};

int main() {

    std::vector<int> v{4, 1, 2, 1, 2};

    Solution solution;
    std::cout << solution.singleNumber(v) << '\n';

    return 0;
}
