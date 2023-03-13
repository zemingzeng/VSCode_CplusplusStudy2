#include "CplusplusStudy.hpp"
#include "Util.hpp"
using namespace mingzz;

int main()
{
    Util::LOGI("  ");
    Util::LOGI("  ");
    Util::LOGI("------------------------------------------------- ");
    Util::LOGI("|         using c++ standard---->%ld          | ", __cplusplus);
    Util::LOGI("------------------------------------------------- ");
    Util::LOGI("  ");
    Util::LOGI("  ");

    CplusplusStudy cplusplusStudy;
    cplusplusStudy.study();
    return 0;
}