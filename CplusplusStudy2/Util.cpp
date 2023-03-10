#include "Util.hpp"
#include <iostream>
#include <cstring>
namespace mingzz
{
    int Util::LOGI(const char *__format, ...)
    {
        const char *endC{"\n"};
        char *format{new char[strlen(__format) + 1]};
        strcpy(format, __format);
        strcat(format, endC);
        int __retval;
        __builtin_va_list __local_argv;
        __builtin_va_start(__local_argv, __format);
        __retval = __mingw_vfprintf(stdout, (const char *)format, __local_argv);
        __builtin_va_end(__local_argv);
        return __retval;
    }
}