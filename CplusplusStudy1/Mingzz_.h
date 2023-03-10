#include "Mingzz.h"

class M : public Mingzz
{
public:
    virtual void B();
    virtual void C();
    virtual void A();
};

class J : public M
{
public:
    void A();
    void B();
    void C();
#include "ming.h"
};