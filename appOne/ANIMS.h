#pragma once
#include"ANIM.h"
class ANIMS{
private:
    int NumAnims = 0;
    class ANIM** Anims = 0;
public:
    ANIMS();
    ANIMS(const char* path);
    ~ANIMS();
    void load(const char* path);
    //getter
    class ANIM* anim(int animIdx);
};

