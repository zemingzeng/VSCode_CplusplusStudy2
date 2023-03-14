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
#include <format.h>

auto autoMethod(auto &context)
{
    context.begin();
    return "i am auto method!!!";
}

using namespace std;
using mingzz::Util;
using stringView = std::string_view;
class Apple
{
public:
    int price{0};
    Apple(int price_)
    {
        price = price_;
    }
    void begin()
    {
    }
};

void tempTest();

#include <numbers>

void CplusplusStudy::study()
{
    Util::LOGI("\nStart-----------------------------------------------------------------------");
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
    stringView string_view1 = string4;
    Util::LOGI("string4修改前的string_view length:%d", string_view1.length());
    string4 += " is MVP";
    // 在使用string_view时一定要确保它的有效性，比如它所指的string可能已经经过重新分配内存的操作了
    // 这样它就可能变得无效（即使它的data还能使用，但是还是得避免使用它，因为可能出现未定义的行为）
    Util::LOGI("string4修改后的string_view length:%d", string_view1.length());
    string_view1 = string4;
    Util::LOGI("最后的string_view length:%d", string_view1.length());

    Util::LOGI("\n-----------------20230313----------------------");
    string string5{"123"};
    stringView string_view2{string5 + "456"}; // 最好不能这么使用string_view这样会造成dangling pointer
    Util::LOGI("string_view2 data:%s", string_view2.data());
    auto string_view3{"Ni hao"sv};
    Util::LOGI(R"(sv 限定符,用auto推断会推断成string_view: auto string_view3{"Ni hao"sv})");
    Util::LOGI("size of wchar_t:%d", sizeof(wchar_t));
    // auto formatType = fmt::format("使用format来输出int=5的二进制:{:b}", 5);
    Util::LOGI("使用format来输出int=5的二进制:%s", fmt::format("{:b}", 5).data());

    Util::LOGI("\n-----------------20230314----------------------");
    string string6{"xxxxx"};
    stringView string_view4{string6};
    string string7{string_view4};
    Apple autoMethodParam{1};
    Util::LOGI(autoMethod(autoMethodParam));
    Util::LOGI("std::numbers中定义的常量pi:%.18f", numbers::pi);
    // memory
    int **ppInt{nullptr};
    ppInt = new int *;
    *ppInt = new int(5);
    Util::LOGI("当前的系统的指针占用内存字节:%d", sizeof(int *));
    Util::LOGI("指针也可以分配在free store内存中比如:\nint **ppInt{nullptr};ppInt = new int *;*ppInt = new int;\nppInt在stack区:%p,*ppInt在free store区:%p,最后的new int也在free store区:%p",
               &ppInt, ppInt, *ppInt);
    delete *ppInt;
    *ppInt = nullptr;
    delete ppInt;
    ppInt = nullptr;
    Util::LOGI("释放二级指针的顺序应该是:1. delete *ppInt; 2. *ppInt = nullptr; 3. delete ppInt; 4. ppInt = nullptr;");
    int *pInt1 = new (nothrow) int;
    if (nullptr == pInt1)
    {
        // 分配失败
    }
    delete pInt1;
    pInt1 = nullptr;
    Util::LOGI("一般情况下用new分配内存,分配失败则会抛异常,但是用int* p = new(nothorw) int;分配内存时分配失败则会返回空指针!");
    Apple *apple4{new Apple[2]{Apple(3), Apple(4)}};
    delete[] apple4;
    apple4 = nullptr;
    int(*ppInt1)[2] = {new int[2][2]}; // 数组指针
    delete[] pInt1;
    /**
     在C和C++中，当数组作为函数参数时，它会退化为指向数组第一个元素的指针。
     所以 void arrayMethod(int arr[4])、void arrayMethod(int *arr)、
     void arrayMethod(int arr[]) 和 void arrayMethod(int arr[n]) 都是等价的。
     的看传进来的参数是什么。
     然而void arrayMethod(int (&arr)[4])；此函数就必须传int[4]的参数
     当你试图访问指针外的地址时，可能会发生越界访问。越界访问可能会导致程序崩溃，也可能不会。
     这取决于操作系统如何处理这种情况。在某些情况下，操作系统可能会检测到越界访问并终止程序运行；
     在其他情况下，程序可能会继续运行，但其行为将变得不可预测。因此，应该避免越界访问。
     比如”int* p{new int}; (p+12)=10;“像这种就是未定义的行为
     */
    // int &arra[5]; c++中不能定义引用数组，因为引用是别名，没内存，数组所以无法分配内存



    

    // temp test
    tempTest();
    Util::LOGI("\nEnd-----------------------------------------------------------------------");
}

template <>
class fmt::formatter<Apple>
{
};

void arrayMethod(int arr[4])
{
    *(arr) = 10;
    Util::LOGI("arrayMethod arr指向的地址值是:%d", *arr);
}
// void arrayMethod1(int &arr[4])
// {
// }

void tempTest()
{
    int temp = 9;
    // int *arrayInt{new int[4]};
    int *arrayInt = &temp;
    // 其实接收的一个指针
    arrayMethod(arrayInt);
}
