#include "CplusplusStudy.hpp"
#include <iostream>
#include <cstring>
#include <string>

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
using mingzz::Util;

class Apple
{
public:
    int price{0};
    Apple(int price_)
    {
        price = price_;
    }
};

void CplusplusStudy::study()
{

    Util::LOGI("this c++ study program!!!!!");

    Util::LOGI("\n-----------------20230308----------------------");
    Util::LOGI("<=> study:");
    string str1{"ghd"};
    string str2{"dfd"};
    Util::LOGI("str1-->%s", str1.c_str());
    Util::LOGI("str2-->%s", str2.c_str());
    auto result{str1 <=> str2};
    if (is_gt(result))
        Util::LOGI("str1 greater than str2");
    if (is_lt(result))
        Util::LOGI("str1 less than str2");
    if (is_eq(result))
        Util::LOGI("str1  equal  str2");

    Util::LOGI("\n-----------------20230309----------------------");
    auto str3{"hello world"};  // 解释为const char*
    auto str4{"hello world"s}; // 解释为string
    Util::LOGI("str3:%s  str4:%s", str3, str4.c_str());
    // using namespace ming::ming2;
    // ming::ming1::intA causes ambiguous
    Util::LOGI("inline namespace intA : %d", ming::ming1::ming2::intA);
    long double number1{3.143333333};
    string numberStr{to_string(number1)};
    Util::LOGI("numberStr : %s", numberStr.c_str());
    string str5(20, 'x');
    auto result1{to_chars(str5.data(), str5.data() + 5, 12345)};
    Util::LOGI("size str5:%d result1.ec:%d str5:%s", str5.size(), result1.ec, str5.c_str());
    // Using structured bindings
    /**struct to_chars_result
        {
          char* ptr;
          errc ec;
        }
     *
     */
    auto [ptr, ec] = to_chars(str5.data(), str5.data() + 5, 12345);
    Util::LOGI("struct bindings ptr:%s ec:%d", ptr, ec);

    Util::LOGI("\n-----------------20230311----------------------");
    int number2 = 1;
    // int number3 = (number2++) + (number2++); 未定义的行为
    // int number3 = (++number2) + number2;  未定义的行为
    int number3 = (++number2) + 1;
    Util::LOGI("number3:%d", number3);

    Util::LOGI("\n-----------------20230312----------------------");
    /**
     * 列表初始化有一些优点：
       1.列表初始化可以防止窄化转换（narrowing conversion）。例如，如果你试图使用一个浮点数来初始化一个整数，列表初始化会报错，而圆括号初始化不会。
       2.列表初始化可以用来初始化聚合类型（aggregate type），例如数组和结构体。这在圆括号初始化中是不可能的。
       3.列表初始化语法更加统一，可以用来初始化几乎所有类型的对象。
     *
     */
    Util::LOGI("C++11 引入的列表初始化（list initialization）语法，可替代圆括号初始化（parentheses initialization）");
    Apple apple1{1};
    Apple apple2 = Apple(1);
    Apple apple3 = Apple{1};
    Util::LOGI("使用各种方式初始化对象：Apple apple1{1}-->price:%d Apple apple2 = Apple(1)-->price:%d Apple apple3 = Apple{1}-->price:%d",
               apple1.price, apple2.price, apple3.price);
    Apple *pApple1 = new Apple{1};
    Apple *pApple2 = new Apple(1);
    Apple *pApple3{new Apple{2}};
    Util::LOGI("使用各种方式初始化对象指针：Apple *pApple1 = new Apple{1}-->price:%d Apple *pApple2 = new Apple(1)-->price:%d Apple *pApple3{new Apple{2}}-->price:%d",
               pApple1->price, pApple2->price, pApple3->price);
    delete pApple1;
    delete pApple2;
    delete pApple3;

    string string1{"hello"};
    string string2{string1};
    Util::LOGI("string1 addr:%p,string2 addr:%p", &string1, &string2);

    string string4{"the shy"};
    string_view string_view1 = string4;
    Util::LOGI("string4修改前的string_view length:%d", string_view1.length());
    string4+=" is MVP";
    //在使用string_view时一定要确保它的有效性，比如它所指的string可能已经经过重新分配内存的操作了
    //这样它就可能变得无效（即使它的data还能使用，但是还是得避免使用它，因为可能出现未定义的行为）
    Util::LOGI("string4修改后的string_view length:%d", string_view1.length());
    string_view1 = string4;
    Util::LOGI("最后的string_view length:%d", string_view1.length());

}