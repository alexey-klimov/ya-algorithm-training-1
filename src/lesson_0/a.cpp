#include <iostream>
#include <sstream>

#include "kisstest.h"

using namespace std::string_literals;

class Solution {
public:
    template <typename In, typename Out>
    static void Run(In& in, Out& out) {
        int a, b;
        in >> a >> b;
        out << a + b << std::endl;
    }
};

void Test1() {
    std::istringstream in;
    std::ostringstream out;

    in.str("1 1");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "2\n");
}

void TestSolution() {
    Test1();
}

int main() {
    TestSolution();
    Solution::Run(std::cin, std::cout);

    return 0;
}
