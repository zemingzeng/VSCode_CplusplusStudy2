//
// Created by zemizeng on 2022/4/7.
//
#ifndef STUDY
#define STUDY

#include "array"
#include "fcntl.h"
#include "iostream"
#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <vector>
#include <cstddef>
#include <list>
#include <memory>
#include <ostream>
#include <thread>

void play_print(const char *info, ...) { printf("%s\n", info); }

namespace play_namespace
{
    namespace zzm
    {
        int a;
        namespace ming
        {
            int a;
        }
    } // namespace zzm
    namespace ming
    {
        void test()
        {
            zzm::a = 9;
            zzm::ming::a = 89;
            play_print("namespace ming test method!");
        }
    } // namespace ming
    namespace zeng
    {
        void test() { play_print("namespace zeng test method!"); }
    } // namespace zeng

    void play()
    {
        ming::test();
        zeng::test();
        ::play_print(
            "use global namespace(not under some namespace things)---->'::' ");
    }
} // namespace play_namespace

namespace play_number_binary_octal_hex_show
{
    void play()
    {
        int a = 020;
        printf("八进制 020-->%d\n", a);
        a = 0b11;
        printf("二进制 0b11-->%d\n", a);
        a = 0x10;
        printf("十六进制 0x10-->%d\n", a);
    }
} // namespace play_number_binary_octal_hex_show
namespace play_enum
{
    // 建议用强制类型的enum class 代替 enum
    enum class Play : unsigned long long
    {
        A = 100,
        B,
        C
    };
    enum Play1
    {
        A,
        B,
        C
    };

    void play()
    {
        Play a = Play::A;
        Play1 b = Play1::B;
        Play *play1;
        if (b > 0)
        {
            play1 = new Play(Play::B);
        }
        // 非强类型的enum总是被解释为int所以可以用来比较int,但是强制类型的enum就不行
        //        if(a>0){
        //
        //        }
        printf("强制类型的enum class --->%d\n", *play1);
        printf("强制类型的enum class byte size--->%d\n", sizeof(Play::A));
        delete play1;
    }
} // namespace play_enum

namespace play_if_init
{
    void play()
    {

        if (int a = 0; a > -1)
        {
            printf("if init 语句在-std=c++17时-->if (int a = 0;a > -1)\n");
        }
    }
} // namespace play_if_init

namespace play_struct
{
    struct Play
    {
        int age;
        std::string name;
    };

    void play()
    {
        Play *play1 = new Play();
        play1->name = "ming";
        printf("struct play name--->%s\n", play1->name.c_str());
        delete play1;
        Play play = {.age = 28, .name = "zzm"};
    }
} // namespace play_struct

namespace play_array
{
    // 对c风格的数组进行了简单包装
    // 总是知道自身的大小,不会自动转化成指针,具有迭代器,可方便的遍历元素
    void play()
    {
        std::array<int, 3> array_int3;
        array_int3 = {1, 2, 3};
        printf("array size--->%d\n", array_int3.size());
        printf("array elements 1 array_int3[1]--->%d\n", array_int3[1]);
    }

} // namespace play_array

namespace play_vector
{
    // 用一种更安全和更灵活的机制取代C中数组的概念
    //  vector是动态扩容的,可在运行时删除和添加元素
    // 不需要担心内存的管理,vector自动分配足够的内存来存放元素
    void play()
    {
        std::vector<int> vector_int;
        vector_int.push_back(22);
        vector_int.push_back(32);
        vector_int.push_back(42);
        vector_int.push_back(42);
        vector_int.push_back(42);
        printf("std::vector<int>  size-->%d element 1--->%d  element 0--->%d\n",
               vector_int.size(), vector_int.at(1), vector_int[0]);
    }
} // namespace play_vector

namespace play_virtual_class
{

    // 纯虚类是可以定义方法的,犹如java的abstract class
    // 但是java的接口可以声明方法,但是无法定义方法
    // 如果一个类里面全是纯虚函数,则可以把这个类看作为类似java中的interface
    class Fruit
    {
    public:
        std::string name;

        virtual void play() = 0;

        std::string sayName() { return name; }

        virtual void buy() { printf("buy fruit!!!!\n"); }

        virtual ~Fruit() { printf("~Fruit()!!!!\n"); }
    };

    class Apple : public Fruit
    {
    public:
        virtual void play() override { name = " My name is Apple!!!"; }

        ~Apple() { printf("~Apple()!!!!\n"); }
        // 多态,如果是父类的方法不是private即使子类的方法的是private则
        // 父类的引用也可以调用子类的private的方法,下面的play方法验证了
    public:
        virtual void buy() override { printf("buy apple!!!!\n"); }
    };

    void play()
    {
        Apple apple;
        apple.play();
        std::string name = apple.sayName();
        printf("apple name--->%s\n", name.c_str());
        Fruit *fruit = new Apple;
        fruit->buy();
        delete fruit;
    }

}; // namespace play_virtual_class

namespace play_move_make_unique
{
    class Apple
    {
    public:
        Apple() = default;

        Apple(Apple &a) : Apple(2) {}

        Apple(int a) {}

        void play()
        {
            int a = 0;
            int &b = a;  // 左值引用 = 左值 相当于左值别名
            int &&c = 6; // 右值引用 = 右值 相当于右值别名
            printf("play_move_make_unique Apple\n");
        }
    };

    void play()
    {
        // make_unique和move都是提高性能的存在
        auto ptr = std::make_unique<Apple>();
        ptr->play();
        std::string name = "Apple";
        printf("before move name--->%s\n", name.c_str());
        std::string name_copy = std::move(name);
        printf("after move name--->%s  name_copy--->%s\n", name.c_str(),
               name_copy.c_str());
    }
} // namespace play_move_make_unique

namespace play_array_pointer
{

    int a[4] = {1, 2, 3, 4};

    void array_pointer_test(int *array)
    {
        int size = sizeof(a) / sizeof(int);
        for (int i = 0; i < size; i++)
        {
            printf("array[%d]-->%d\n", i, *array);
            array++;
        }
        int arrays[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
        int(*array_pointer)[4] = arrays; // 数组指针
        int *A = a;
        int *B = a + 1;
        int *C = a + 2;
        int *D = a + 3;
        int *pointer_array[4] = {A, B, C, D}; // 指针数组,[]优先级比*高
        int arr[2][5] = {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
        int(*p1)[2][5] = &arr; // 取地址是指指向整个数组的一个pointer
        int(*p2)[5] = arr;
        int arr1[2] = {1, 2};
        int(*p3)[2] = &arr1;
        /*下面这个是错误的*/
        // int(*p3)[2] = arr1; //arr1只是指向数组第一个元素的地址的指针
    }

    void play() { array_pointer_test(a); }
} // namespace play_array_pointer

namespace play_thread_TLSKey
{

    class Looper
    {
    public:
        std::string name;

        Looper() = default;

        Looper(std::string name) { this->name = std::move(name); }
    };

    pthread_key_t thread_stl_key;
    pthread_once_t thread_once_t;

    void thread_init_key_and_set_key_value();

    void play()
    {
        unsigned a = 0;
        pthread_once(&thread_once_t, thread_init_key_and_set_key_value);
        Looper *looper = static_cast<Looper *>(pthread_getspecific(thread_stl_key));
        printf("current thread stl key-->%d, stl value[name]--->%s once_t-->%d\n",
               thread_stl_key, looper->name.c_str(), thread_once_t);
    }

    void thread_init_key_and_set_key_value()
    {
        pthread_key_create(&thread_stl_key, NULL);
        pthread_setspecific(thread_stl_key, new Looper("NO.1_Looper"));
    }
} // namespace play_thread_TLSKey

namespace play_lamda_using_expression
{
    using using_method = bool (*)(int, int); // c++ 11开始推荐用using来替代定义别名
    bool play_(int a, int b) { return a < b; }

    // C++ 17新特性??
    [[nodiscard]] int play__()
    {
        std::cout << "[[discard]] int play__()" << std::endl;
        return 1;
    }

    class Apple
    {

    public:
        void play(using_method method);

        void test() {}
    };

    void Apple::play(using_method method)
    {
        bool truth = method(1, 2);
        auto method_ = [this](int a) -> int
        {
            test();
            return a;
        };
        method_(99);
    }

    void play()
    {
        int k = 100;
        auto method = [](int a, int b)
        { return a > b; };
        using_method method_ = play_;
        Apple apple;
        apple.play(method);
        std::cout << "using using_method = bool (*)(int, int)-->" << method_(1, 1)
                  << std::endl;
        std::cout << "lamda auto method = [&k](int a, int b) -> bool { return a - "
                     "k > b; }-->"
                  << method(1, 1) << std::endl;
        int x = play__();
    }
} // namespace play_lamda_using_expression

namespace play_define_assert
{
#define ASSERT(x)                                                              \
    {                                                                          \
        if (x)                                                                 \
            printf("Has a Assert Error:\n");                                   \
        printf("===================================Assert Error "              \
               "Details======================================================" \
               "===\n");                                                       \
        printf("File:\"%s\"  Function:\"%s()\"  Line:%d\n", __FILE__,          \
               __FUNCTION__, __LINE__);                                        \
        printf("=============================================================" \
               "===================================================\n");       \
    }
    // __debugbreak();

    void play()
    {
        ASSERT(1);
        std::cout << "ASSERT(x) if(x) __debugbreak();" << std::endl;
    }
} // namespace play_define_assert

namespace play_friend_class
{
    class Fruit
    {

        friend class Apple;

    public:
        int fruit_1;

    private:
        int fruit_2 = 267;
    };

    // 友元类可以访问私有成员
    class Apple
    {
    public:
        Fruit fruit;

        void get_private()
        {
            printf("I am Fruit's friend class Apple and access public int "
                   "fruit_1--->%d\n",
                   fruit.fruit_2);
        }

        // 默认是浅拷贝
        Apple(const Apple &apple) { printf("Apple duplicate method........\n"); }

        Apple() = default;

    private:
        void get_2()
        {
            printf("I am Fruit's friend class Apple and access public int "
                   "fruit_1--->%d\n",
                   fruit.fruit_1);
        }
    };

    void play()
    {
        Apple apple;
        apple.get_private();
        apple.fruit.fruit_1 = 100;
        Apple apple_1(apple);
        printf(
            "apple fruit---->%p  apple_1 fruit---->%p apple_1 fruit fruit_1-->%d\n",
            &apple.fruit, &apple_1.fruit, apple_1.fruit.fruit_1);
    }
} // namespace play_friend_class

namespace play_array_typedef
{

    typedef int INT_32[2];

    void play()
    {
        INT_32 state = {0, 1};
        printf(
            "typedef int INT_32[2]---->INT_32 state = {0, 1}---->[0]:%d,[1]:%d\n",
            state[0], state[1]);
    }

} // namespace play_array_typedef

namespace play_pointer
{

    class Apple
    {
    public:
        void play()
        {
            std::cout << "i am Apple class method play ^_^ " << std::endl;
        }
    };

    using Anything = void *;
    using namespace std;
    void play()
    {
        Anything anything;
        printf("char----->size(bytes):%d\n", sizeof(char));
        printf("void*----->size(bytes):%d\n", sizeof(anything));
        printf("int*----->size(bytes):%d\n", sizeof(int *));
        // printf("byte*----->size(bytes):%d\n", sizeof(std::byte* ));

        auto *apple = new Apple;
        std::cout << "--------" << sizeof(apple) << std::endl;
        int a = 90;
        int *a_p = &a;
        std::cout << "--------" << sizeof(a_p) << std::endl;
        std::cout << "Apple *apple address--->" << apple << std::endl;
        auto apple_address = reinterpret_cast<long long>(apple);
        std::cout << "  int size-->" << sizeof(int) << "  long size-->"
                  << sizeof(long) << "  int long long-->" << sizeof(long long)
                  << std::endl;
        std::cout << "Apple *apple address(reinterpret_cast<long long>(apple))--->"
                  << apple_address << std::endl;
        auto apple_ = reinterpret_cast<Apple *>(apple_address);
        apple_->play();
        if (apple)
            delete apple;

        // smart pointer becasue of stack memory to release tmp object
        // to release pointer
        unique_ptr<int> u_ptr = make_unique<int>(3);
        shared_ptr<int> s_ptr = make_shared<int>(4);
        printf("u_ptr---->%d  s_ptr---->%d\n", u_ptr.get(), s_ptr.get());
    }

    /**
     * 假设设计一个二叉树，并在其中包含一个指向左右子节点的指针
     * 运行正常，调用3次构造函数和3次析构函数，输出如下：
     * Constructor
     * Constructor
     * Constructor
     * 1
     * 1
     * 1
     * Destructor
     * Destructor
     * Destructor
     */
    class Node
    {
        int value;

    public:
        shared_ptr<Node> leftPtr;
        shared_ptr<Node> rightPtr;
        // 如果给每个节点添加一个父节点时，则导致share_ptr内测泄漏。
        //     shared_ptr<Node> parentPtr;
        // 使用弱引用进行处理，交叉引用不递增计数器
        //  weak_ptr<Node> parentPtr;
        shared_ptr<Node> parentPtr;
        Node(int val) : value(val) { cout << "Constructor" << endl; }
        ~Node() { cout << "Destructor" << endl; }
    };

    void play_1()
    {
        cout << "play_1 : " << endl;
        shared_ptr<Node> ptr = make_shared<Node>(4);
        ptr->leftPtr = make_shared<Node>(2);
        ptr->rightPtr = make_shared<Node>(5);
        cout << ptr.use_count() << endl;
        cout << ptr->leftPtr.use_count() << endl;
        cout << ptr->rightPtr.use_count() << endl;
    }

    void play_2()
    {
        shared_ptr<Node> ptr = make_shared<Node>(4);
        cout << "play_2 : " << endl;
        cout << "shared_ptr<Node> ptr = make_shared<Node>(4):  " << ptr.use_count()
             << endl;
        ptr->leftPtr = std::make_shared<Node>(2);
        cout << "ptr->leftPtr = std::make_shared<Node>(2):  " << ptr.use_count()
             << endl;
        ptr->leftPtr->parentPtr = ptr;
        cout << " ptr->leftPtr->parentPtr = ptr:  " << ptr.use_count() << endl;
        ptr->rightPtr = std::make_shared<Node>(5);
        cout << " ptr->rightPtr = std::make_shared<Node>(5):  " << ptr.use_count()
             << endl;
        ptr->rightPtr->parentPtr = ptr;
        cout << "ptr->rightPtr->parentPtr = ptr:  " << ptr.use_count() << endl;

        cout << "ptr->leftPtr.use_count():  " << ptr->leftPtr.use_count() << endl;
        cout << "ptr->rightPtr.use_count():  " << ptr->rightPtr.use_count() << endl;
        // ptr.reset();
        // cout << "shared_ptr<Node> ptr = make_shared<Node>(4):  " <<
        // ptr.use_count()
        //      << endl;
        ptr->leftPtr->parentPtr.reset();
        cout << "shared_ptr<Node> ptr = make_shared<Node>(4):  " << ptr.use_count()
             << endl;
        ptr->rightPtr->parentPtr.reset();
        cout << "shared_ptr<Node> ptr = make_shared<Node>(4):  " << ptr.use_count()
             << endl;
        ptr.reset();
        cout << "shared_ptr<Node> ptr = make_shared<Node>(4):  " << ptr.use_count()
             << endl;
        shared_ptr<Node> ptr_1 = make_shared<Node>(99);
        shared_ptr<Node> ptr_2 = ptr_1;
        shared_ptr<Node> ptr_3 = ptr_2;
        ptr_3.reset();
    }

} // namespace play_pointer

namespace play_parent_sub_class
{
    class Fruit
    {
    };

    class Apple : public Fruit
    {
    public:
        int color = -1;
        int price = -1;

        Apple()
        {
            color = // 头见这样赋值的方式
                price = 89;
        }
    };

    void play()
    {

        auto *apple_ = new Apple;
        Fruit *apple = new Apple;

        printf("class Apple : public Fruit so we can use Fruit like this--> [Fruit "
               "*apple = new Apple] \n");
        printf("Apple color { color =   \n"
               "              price = 89; }---->%d \n",
               apple_->color);
    }
} // namespace play_parent_sub_class

namespace play_operator
{

    class Apple
    {
    public:
        // Apple(const Apple & apple)=default ;//delete 对其进行禁用
        // Apple(Apple&&)=default;

        // Apple &operator=(const Apple &)= delete;

        void play() = delete;

        void play_() {}
        // Apple(Apple &a) {};
        // Apple( ){};
        // Apple( int ) {};
        int price;

    private:
    };

    void play()
    {
        Apple apple;
        //        Apple apple1(apple);  error
        //        apple.play();  error
        Apple{}.play_();
        Apple{.price = 10}.price;
    }
} // namespace play_operator

namespace play_class_extends_struct
{

    struct Play
    {
        float time = 12.99f;
    };

    class Play_ : public Play
    {
    };

    void play()
    {

        Play_ play;

        std::cout << "this is Play_ extends struct Play member time --->"
                  << play.time << std::endl;
    }

} // namespace play_class_extends_struct

namespace play_std_thread
{
    class Apple
    {
    public:
        std::thread mThread;

        std::thread *threadStart()
        {
            mThread = std::thread(
                [this]() -> int
                {
            applePlay();
            return 0; });
            return &mThread;
        }

        void applePlay() { printf("i am in std::thread.. applePlay \n"); }

        void wait() { mThread.join(); }
    };

    void play()
    {
        Apple apple;
        apple.threadStart();
        apple.wait();
    }

} // namespace play_std_thread

namespace play_class_methods
{

    class Apple
    {

    public:
        int getPrice();

        int hook_getPrice()
        {
            return 0;
        }

        Apple()
        {
            //          std::list
            //            memset();
        }
    };

    void play() {}

} // namespace play_class_methods

namespace struct_play
{

    struct Apple
    {
        int a = 0;
    };

    struct A : Apple
    {
    };

    A apple;

    void play() { apple.a; }
} // namespace struct_play

namespace template_play
{

    template <typename T_, int I, typename TT_>
    class Apple
    {

    public:
        T_ t;
        TT_ tt;

        T_ play() { return t; }
    };

    void play()
    {
        Apple<double, 9, bool> apple{.t = 9.0f, .tt = true};
        double t = apple.play();
    }

} // namespace template_play

namespace play_memory
{

    class Apple
    {
    public:
        int price;
    };

    void play()
    {
        // heap copy to stack
        Apple apple_1 = *new Apple(); // leak memory
        Apple *apple_2 = new Apple();
        Apple apple_3 = *apple_2;
        printf("namespace memory_play apple_1 stack address-->%p\n", &apple_1);
        printf("namespace memory_play apple_2 heap address-->%p\n", apple_2);
        printf("namespace memory_play &apple_2 stack address-->%p\n", &apple_2);
        printf("namespace memory_play apple_3 stack address-->%p\n", &apple_3);
        delete apple_2;
    }

} // namespace play_memory

namespace play_cplusplus_memory
{
    long long apple_address = 0l;
    class Apple
    {
    public:
        int price;
        ~Apple()
        {
            printf("play_cplusplus_memory-->Apple Deconstruction..........\n");
        }
    };
    void play()
    {
        static Apple apple;
        apple.price = 190;
        apple_address = (long long)(&apple);
        // apple_address = (long )(&apple);
        printf("play_cplusplus_memory-->sizeof(long long):%d  sizeof(Apple*):%d  sizeof(long):%d\n",
               sizeof(long long), sizeof(&apple), sizeof(long));
        printf("play_cplusplus_memory-->apple_address : %x\n", apple_address);
        // Apple apple_1;
        // Apple apple = *new Apple(); // memory leak
        // final int a=10;
    }
    //   final Apple apple_2;
    void play_1()
    {
        int price = (*(Apple *)apple_address).price;
        printf("play_cplusplus_memory-->(*(Apple*)apple_address).price : %d\n", price);
    }
}

namespace play_thread_mutex
{
    class Apple
    {
    public:
        // Apple(int);
        // Apple(const Apple &apple);
        int *const p = new int(6);
    };

    pthread_mutex_t mutex_t;
    pthread_cond_t cond_t;

    void play()
    {

        // 必须手动销毁否则内存泄漏
        pthread_mutex_init(&mutex_t, NULL);
        // 销毁
        pthread_mutex_destroy(&mutex_t);

        // 阻塞加锁,加不上就会一直加
        pthread_mutex_lock(&mutex_t);
        // 非阻塞式加锁，需要搭配循环判断返回值
        pthread_mutex_trylock(&mutex_t);
        // 带有超时间的加锁
        //  pthread_mutex_timedlock();

        // 以上三种加锁都可以用此解锁
        pthread_mutex_unlock(&mutex_t);

        // 这种初始化就是系统帮忙回收
        pthread_mutex_t mutex_t_1 = PTHREAD_MUTEX_INITIALIZER;

        // 初始化条件变量
        // 条件变量属性attr，一般使用null，使用默认属性
        pthread_cond_init(&cond_t, NULL);
        // 销毁
        pthread_cond_destroy(&cond_t);
        // 静态初始化(系统会自己释放)
        cond_t = PTHREAD_COND_INITIALIZER;

        // 等待接口，在其内部会释放互斥锁"mutex_t"
        pthread_cond_wait(&cond_t, &mutex_t);

        // 唤醒一个线程
        pthread_cond_signal(&cond_t);
        // 唤醒所有线程
        pthread_cond_broadcast(&cond_t);

        // Apple apple;
        int p_ = 10;
        int *p = &p_;
        delete p;

        Apple apple;
        Apple apple_(apple);
    }
}

namespace play_copy_construct_method
{

    class Apple
    {
    public:
        int price = 10;
        Apple()
        {
            printf("play_copy_construct_method Apple()\n");
        }
        Apple(int price)
        {
            this->price = price;
            printf("play_copy_construct_method Apple(int price)\n");
        }
        Apple(const Apple &a)
        {
            printf("play_copy_construct_method Apple(const Apple&)\n");
        }
        // Apple(Apple &&a)
        // {
        //     printf("play_copy_construct_method move Apple( Apple&&)\n");
        // }
        ~Apple()
        {
            printf("play_copy_deconstruct_method  ~Apple()\n");
        }
        bool operator=(Apple &)
        {
            printf("play_copy_deconstruct_method  operator=(Apple &)\n");
            return 0;
        }
    };

    Apple returnTest()
    {
        // 局部最好别返回
        Apple b;
        // Apple &a = b;
        return b;
    };
    void play()
    {
        // 会调用构造函数
        Apple apple;

        // 只调用了拷贝构造函数
        Apple apple_ = apple;

        Apple a(20);
        Apple b;
        b = a;
        printf("play_copy_construct_method Apple a:%p-->price:%d  b:%p-->price:%d\n", &a, a.price, &b, b.price);

        Apple retun_ = returnTest();
        printf("play_copy_construct_method retun_ returnTest() price:%d\n", retun_.price);
        // Apple apple_1 = std::move(retun_);
    }

}

namespace play_class_internal_define
{

    class Apple_
    {
    private:
        int a;

    public:
        void access_a();
        void access_a_();
    };
    class Apple
    {
    private:
        int a;

    public:
        friend void play_(Apple &apple);
        // void Apple_::access_a()
        // {
        //     // this->a; 访问不到Apple_的a变量
        // }
    };
    void Apple_::access_a_()
    {
        this->a; // 在外面定义就可以访问
    }
    void play()
    {
    }
    void play_(Apple &apple)
    {
        apple.a;
    }
}

namespace play_c_cplusplus_momory
{

    int a = 10;         // 存储在data段
    int a1;             // 存储在bss段
    int static b;       // 存储在bss段
    int static b1 = 10; // 存储在data段
    char c[] = "hello"; // 存储在代码段

}

namespace play_pointer_size
{

    void play()
    {
        char a = 'c';
        char *c_p_a = &a;
        int b = 10;
        int *i_p_b = &b;
        printf("size of char* --->%d\n", sizeof(c_p_a));
        printf("size of int* --->%d\n", sizeof(i_p_b));
        uint8_t *ii;
    }

}

namespace play_caculate
{

    void play()
    {
        int i = 1;
        int a = (++i) + (++i);
        printf("i = 1 ---> (++i)+(++i) :%d\n", a);
    }

}

namespace play_global_enum
{

    class Apple
    {

    public:
        enum audio_device_enum
        {
            DEVICE_OUT_SPEAKER = 0X10
        };

        const static int DEVICE_OUT_SPEAKER_ = 0;
    };

    // Apple::DEVICE_OUT_SPEAKER;
    void
    play()
    {
        Apple::audio_device_enum audio_device = Apple::DEVICE_OUT_SPEAKER;
        // Apple::DEVICE_OUT_SPEAKER_ = 9;
    };

}

namespace play_address_before_op
{

    void play()
    {
        int a = 100;
        printf("play_address_before_op a addr : %p\n", &a);
        int b = 90;
        printf("play_address_before_op b addr : %p\n", &b);
        int *p = (int *)((long long)(&b) - 0x0c);
        printf("play_address_before_op p addr : %p\n", &p);
        int c;
        printf("play_address_before_op c addr : %p\n", &c);
        *p = 1000;
        printf("play_address_before_op c : %d\n", c);

        char *ctrP = "hello";
        // *ctrP ='k';
        char strs[] = "ASD";
        *strs = 'd';
        printf("play_address_before_op size : %d\n", sizeof(strs));
        printf("play_address_before_op size : %d\n", sizeof("hello"));
    }

} // namespace name

namespace play_array_pointer_1
{

    void play()
    {
        int a[] = {11, 22, 33};
        int count = 3;
        int b[count];
        int c = 90;
        for (int i = 0; i < count; i++)
        {
            /* code */
            printf("play_array_pointer ints a: %d\n", a[i]);
        }
        for (int i = 0; i < count; i++)
        {
            /* code */
            printf("play_array_pointer ints b: %d\n", b[i]);
        }

        auto p = &a;
        printf("play_array_pointer &a: %p\n", &a);
        printf("play_array_pointer a: %p\n", a);
        printf("play_array_pointer sizeof(*a): %p\n", sizeof(*a));
        printf("play_array_pointer &a+1: %p\n", &a + 1);
        printf("play_array_pointer (long long)(a): %p\n", (long long)(a));
        printf("play_array_pointer sizeof(*p): %d  %d\n", sizeof(a), sizeof(*p));
        printf("play_array_pointer &a+1 = sizeof(*(&a))+(long long)(&a) : %p \n", sizeof(*(&a)) + (long long)(&a));
        printf("play_array_pointer a+1 = sizeof(*(a))+(long long)(a) : %p \n", sizeof(*(a)) + (long long)(a));
        printf("play_array_pointer a+1 : %p \n", a + 1);

        int yy[2][4];
        int(*p_)[4] = yy;
        int *p__[4] = {nullptr};
    }
}

namespace play_method_pointer
{

    int play_(char *const a, size_t b) { return 9; };
    typedef int (*METHOD_P)(char *const, size_t);
    long int64_num = 98999;
    METHOD_P method_p = play_method_pointer::play_;

    void play()
    {
        printf("play_method_pointer int64_num : %lld \n", int64_num);

        char *chr = "abcd";
        printf("play_method_pointer chr : %p \n", chr);
        printf("play_method_pointer *chr++ : %c  chr : %p\n", *chr++, chr);
        printf("play_method_pointer chr : %c \n", *chr);
        char chr_ = *chr++;
        printf("play_method_pointer chr_ : %c \n", chr_);
        printf("play_method_pointer chr_ : %c \n", chr_);
        const char *const AAA = "mingzz";

        //  * 0 --- 1
        //  * | \   |
        //  * |  \  |
        //  * |   \ |
        //  * 3 --- 2
        //  *
        printf("'\n");
        printf("0 --- 1\n");
        printf("| \\   |\n");
        printf("|  \\  |\n");
        printf("|   \\ |\n");
        printf("3 --- 2\n");
    }

    void copyChr(char *dest, const char *src)
    {
        while (*dest++ = *src++)
        {
            /* code */
            int a[2][5];
            int *p_[4];
            int(*p)[4];
        }
    }

}

namespace play_struct_
{

    typedef struct
    {
        /* data */
        double b;
        char a[5];
        int c;
        int d;
        int e;

    } mingzz;

    void play()
    {

        printf("play_struct mingzz size : %d\n", sizeof(mingzz));
    }

    void (*p)();

}

namespace play_complex_method
{

    typedef void (*PP)(int);

    void (*hello(int, void (*)(int)))(int)

    {

        PP p;

        return p;
    }

    PP hello_(int, void (*)(int))
    {
        return nullptr;
    };

    typedef int (*(*flush[])())[];
    // 是一个返回数组指针，参数是空的函数指针 数组

    typedef int (*p_arry)[12];

    int (*hello__())[12]
    {
        int a[12];
        return nullptr;
        // return &a;
    };

    p_arry hello___()
    {
        int a[12];
        return nullptr;
        // return &a;
    }

    typedef int (*(PPP()))[];

    int (*(P()))[]
    {
        printf("play_complex_method -->int (*(P()))[] \n");
        return nullptr;
    }

    void play()
    {
        // flush flush_ = {};
        int a[12];
        p_arry p = &a;
        // int(*pp)[] = &a;
        hello__();
        // hello___;
        hello(2, nullptr);
        // PPP pp = P;
        flush b = {P};
        (b[0])();
        // setvbuf 8k 默认的缓冲数据大小 ---> java
    }

}

namespace play_virtual_method
{

    class Apple
    {
    public:
        virtual void A() = 0;
        virtual void B() = 0;
        virtual void C() = 0;
    };

    class Apple_1 : public Apple
    {
    public:
        void A()
        {
        }
    };

    class Apple_2 : public Apple_1
    {
    public:
        void B()
        {
            Apple_1::A();
        }
        void C()
        {
        }
    };

    void play()
    {
        // Apple_1::B();
        Apple_2 apple;
        apple.B();
        // Apple_1 apple_1;
    }

}

void cpp_begin() { printf("\ncpp play begin !!\n\n"); }

void cpp_end() { printf("\ncpp play end !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"); }

#endif