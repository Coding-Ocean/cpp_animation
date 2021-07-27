#define 複数のアニメーション
//#define １つのアニメーション
//#define ループしないアニメーション

#ifdef 複数のアニメーション
#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"ANIMS.h"
void gmain() {
    window(200, 200, full);
    hideCursor();

    ANIMS* anims = new ANIMS("assets\\player");
    ANIM_DATA data;
    data.interval = 0.1f;
    int animIdx = 0;
    
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();

        bool inputFlag = false;
        if (isPress(KEY_D)) { animIdx = 0; inputFlag = true; }
        if (isPress(KEY_A)) { animIdx = 1; inputFlag = true; }
        //if (isPress(KEY_S)) { animIdx = 2; inputFlag = true; }
        //if (isPress(KEY_W)) { animIdx = 3; inputFlag = true; }
        if (inputFlag == false ) {
            data.reset();
        }

        clear(60, 180, 60);
        rectMode(CENTER);
        anims->anim(animIdx)->draw(&data, width / 2, height / 2);
    }
    delete anims;
}
#endif

#ifdef １つのアニメーション
#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"ANIM.h"
void gmain() {
    window(200, 200, full);
    hideCursor();

    ANIM* anim = new ANIM("assets\\bat\\0");
    ANIM_DATA data;
    data.interval = 0.1f;

    initDeltaTime();
    while (notQuit) {
        setDeltaTime();

        clear(180, 80, 80);
        rectMode(CENTER);
        anim->draw(&data, width / 2, height / 2);
    }
    delete anim;
}
#endif

#ifdef ループしないアニメーション
#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"ANIM.h"
void gmain() {
    window(200, 200, full);
    hideCursor();

    ANIM* anim = new ANIM("assets\\explosion\\0");
    ANIM_DATA data;
    data.interval = 0.032f;
    int hp = 0;

    initDeltaTime();
    while (notQuit) {
        setDeltaTime();

        if (hp == 0 && isTrigger(KEY_SPACE)) {
            data.reset();
            hp = 1;
        }
        if (anim->end(data)) {
            hp = 0;
        }
        clear(60, 100, 180);
        rectMode(CENTER);
        if (hp >= 0) {
            anim->drawOnce(&data, width / 2, height / 2);
        }
    }
    delete anim;
}
#endif
