/* C. Телефонные номера
 *
 * Телефонные номера в адресной книге мобильного телефона имеют один из следующих форматов:
 * +7<код><номер>, 8<код><номер>, <номер>, где <номер> — это семь цифр, а <код> — это три цифры или
 * три цифры в круглых скобках. Если код не указан, то считается, что он равен 495. Кроме того, в
 * записи телефонного номера может стоять знак “-” между любыми двумя цифрами (см. пример). На
 * данный момент в адресной книге телефона Васи записано всего три телефонных номера, и он хочет
 * записать туда еще один. Но он не может понять, не записан ли уже такой номер в телефонной книге.
 * Помогите ему! Два телефонных номера совпадают, если у них равны коды и равны номера. Например,
 * +7(916)0123456 и 89160123456 — это один и тот же номер.
 *
 * Формат ввода
 * В первой строке входных данных записан номер телефона, который Вася хочет добавить в адресную
 * книгу своего телефона. В следующих трех строках записаны три номера телефонов, которые уже
 * находятся в адресной книге телефона Васи. Гарантируется, что каждая из записей соответствует
 * одному из трех приведенных в условии форматов.
 *
 * Формат вывода
 * Для каждого телефонного номера в адресной книге выведите YES (заглавными буквами), если он
 * совпадает с тем телефонным номером, который Вася хочет добавить в адресную книгу или NO
 * (заглавными буквами) в противном случае.
 */

#include <iostream>
#include <sstream>

#include "kisstest.h"

using namespace std::string_literals;

class Solution {
public:
    template <typename In, typename Out>
    static void Run(In& in, Out& out) {
        std::string new_number;
        in >> new_number;
        new_number = NormalizeNumber(new_number);
        for (int i = 0; i < 3; ++i) {
            std::string old_number;
            in >> old_number;
            if (new_number == NormalizeNumber(old_number)) {
                out << "YES"s << std::endl;
            } else {
                out << "NO"s << std::endl;
            }
        }
    }

    static std::string NormalizeNumber(const std::string& number) {
        std::string normalized_number = ""s;
        for (char c : number) {
            if (c >= '0' && c <= '9') {
                normalized_number += c;
            }
        }
        if (normalized_number.size() != 11) {
            normalized_number = "8495"s + normalized_number;
        }
        normalized_number[0] = '8';

        return normalized_number;
    }
};

void Test1() {
    std::istringstream in;
    std::ostringstream out;

    in.str("8(495)430-23-97\n+7-4-9-5-43-023-97\n4-3-0-2-3-9-7\n8-495-430");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "YES\nYES\nNO\n");
}

void Test2() {
    std::istringstream in;
    std::ostringstream out;

    in.str("86406361642\n83341994118\n86406361642\n83341994118");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "NO\nYES\nNO\n");
}

void Test3() {
    std::istringstream in;
    std::ostringstream out;

    in.str("+78047952807\n+78047952807\n+76147514928\n88047952807");
    Solution::Run(in, out);
    KISSTEST::ASSERT_EQUAL(out.str(), "YES\nNO\nYES\n");
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
