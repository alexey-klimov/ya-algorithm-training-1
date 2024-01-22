/* D. Уравнение с корнем
 *
 * Решите в целых числах уравнение:
 * sqrt(ax + b) = c,
 * a, b, c – данные целые числа: найдите все решения или сообщите, что решений в целых числах нет.
 *
 * Формат ввода
 * Вводятся три числа a, b и c по одному в строке.
 *
 * Формат вывода
 * Программа должна вывести все решения уравнения в порядке возрастания, либо NO SOLUTION (заглавными
 * буквами), если решений нет. Если решений бесконечно много, вывести MANY SOLUTIONS.
 */

#include <iostream>
#include <sstream>

#include "kisstest.h"

using namespace std::string_literals;

class Solution {
public:
    template <typename In, typename Out>
    static void Run(In& in, Out& out) {
        int a, b, c;
        in >> a >> b >> c;

        if (c < 0) {
            out << "NO SOLUTION"s << std::endl;
            return;
        }

        if (a == 0 && c * c == b) {
            out << "MANY SOLUTIONS"s << std::endl;
            return;
        }

        if (a == 0) {
            out << "NO SOLUTION"s << std::endl;
            return;
        }

        int x = (c * c - b) / a;
        if ((a * x + b) == c * c) {
            out << x << std::endl;
        } else {
            out << "NO SOLUTION"s << std::endl;
        }
    }
};

void Test1() {
    std::istringstream in;
    std::ostringstream out;

    in.str("1\n0\n0\n");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "0\n");
}

void Test2() {
    std::istringstream in;
    std::ostringstream out;

    in.str("1\n2\n3\n");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "7\n");
}

void Test3() {
    std::istringstream in;
    std::ostringstream out;

    in.str("1\n2\n-3\n");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "NO SOLUTION\n");
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
