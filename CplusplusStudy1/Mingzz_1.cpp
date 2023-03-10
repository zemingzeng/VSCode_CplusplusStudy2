// #include "Mingzz.h"
#include "Mingzz_.h"

void Mingzz::C()
{
    // A();
    printf("-------mingzz_1 C() ");
}

// void Mingzz::A()
// {
// }

void J::C()
{
    printf("-------J C() ");
}

void J::B()
{
    printf("-------J B() ");
    // M::B();
    // Mingzz::C();
    M::C();
}
void J::A()
{
    // M::A();
    printf("-------J A()  ");
}

void M::C()
{
    printf("-------M C() ");
    this->A();
}
void M::B()
{
    printf("-------M B() ");
}
void M::A()
{

    printf("-------M A() ");
}

void J::Apple::eat()
{
    printf("-----Apple::eat()-----\n");
}