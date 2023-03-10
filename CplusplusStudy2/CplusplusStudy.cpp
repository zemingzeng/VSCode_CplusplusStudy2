#include "CplusplusStudy.hpp"
#include <iostream>
#include <cstring>
#include <string>

int LOGI(const char *__format, ...)
{
    const char *endC{"\n"};
    char *format{new char[strlen(__format) + 1]};
    strcpy(format, __format);
    strcat(format, endC);

    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, format);
    __retval = __mingw_vfprintf(stdout, format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
}

namespace ming
{
    inline namespace ming1
    {
        int intA = 10;
        inline namespace ming2
        {
            int intA = 100;
        }
    }

}

#include <compare>
#include <charconv>

using namespace std;
void CplusplusStudy::study()
{
    LOGI("this c++ study program!!!!!");

    LOGI("\n-----------------20230308----------------------");
    LOGI("<=> study:");
    string str1{"ghd"};
    string str2{"dfd"};
    LOGI("str1-->%s", str1.c_str());
    LOGI("str2-->%s", str2.c_str());
    auto result{str1 <=> str2};
    if (is_gt(result))
        LOGI("str1 greater than str2");
    if (is_lt(result))
        LOGI("str1 less than str2");
    if (is_eq(result))
        LOGI("str1  equal  str2");

    LOGI("\n-----------------20230309----------------------");
    auto str3{"hello world"};  // 解释为const char*
    auto str4{"hello world"s}; // 解释为string
    LOGI("str3:%s  str4:%s", str3, str4.c_str());
    // using namespace ming::ming2;
    // ming::ming1::intA causes ambiguous
    LOGI("inline namespace intA : %d", ming::ming1::ming2::intA);
    long double number1{3.143333333};
    string numberStr{to_string(number1)};
    LOGI("numberStr : %s", numberStr.c_str());
    string str5(20, 'x');
    auto result1{to_chars(str5.data(), str5.data() + 5, 12345)};
    LOGI("size str5:%d result1.ec:%d str5:%s", str5.size(), result1.ec, str5.c_str());
    // Using structured bindings
    /**struct to_chars_result
        {
          char* ptr;
          errc ec;
        }
     *
     */
    auto [ptr, ec] = to_chars(str5.data(), str5.data() + 5, 12345);
    LOGI("struct bindings ptr:%s ec:%d", ptr, ec);

}