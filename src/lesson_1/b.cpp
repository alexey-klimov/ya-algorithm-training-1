/* B. Треугольник
 *
 * Даны три натуральных числа. Возможно ли построить треугольник с такими сторонами. Если это
 * возможно, выведите строку YES, иначе выведите строку NO.
 *
 * Треугольник — это три точки, не лежащие на одной прямой.
 *
 * Формат ввода
 * Вводятся три натуральных числа.
 *
 * Формат вывода
 * Выведите ответ на задачу.
 */

#include <iostream>
#include <sstream>

#include "kisstest.h"

using namespace std::string_literals;

class Solution {
public:
    template <typename In, typename Out>
    static void Run(In& in = std::cin, Out& out = std::cout) {
        int a, b, c;
        in >> a >> b >> c;
        if (a < b + c && b < a + c && c < a + b) {
            out << "YES"s << std::endl;
        } else {
            out << "NO"s << std::endl;
        }
    }
};

void Test1() {
    std::istringstream in;
    std::ostringstream out;

    in.str("3 4 5");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "YES\n");
}

void Test2() {
    std::istringstream in;
    std::ostringstream out;

    in.str("3 5 4");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "YES\n");
}

void Test3() {
    std::istringstream in;
    std::ostringstream out;

    in.str("4 5 3");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "YES\n");
}

void TestSolution() {
    Test1();
    Test2();
    Test3();
}

int main() {
    TestSolution();
    // Solution::Run(std::cin, std::cout);

    return 0;
}
