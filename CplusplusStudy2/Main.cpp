#include <iostream>
#include "CplusplusStudy.hpp"
#include <cstring>
int LOGI_(const char *__format, ...)
{
    const char *endC{"\n"};
    char *format{new char[strlen(__format) + 1]};
    strcpy(format, __format);
    strcat(format, endC);
    int __retval;
    __builtin_va_list __local_argv;
    __builtin_va_start(__local_argv, (const char *)format);
    __retval = __mingw_vfprintf(stdout, (const char *)format, __local_argv);
    __builtin_va_end(__local_argv);
    return __retval;
}

int main()
{
    LOGI_("  ");
    LOGI_("  ");
    LOGI_("------------------------------------------------- ");
    LOGI_("|         using c++ standard---->%ld          | ", __cplusplus);
    LOGI_("------------------------------------------------- ");
    LOGI_("  ");
    LOGI_("  ");

    CplusplusStudy cplusplusStudy;
    cplusplusStudy.study();
    return 0;
}