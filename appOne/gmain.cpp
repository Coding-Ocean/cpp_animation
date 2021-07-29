#define �P�̃A�j���[�V����
//#define ���[�v���Ȃ��P�̃A�j���[�V����
//#define �����̃A�j���[�V����
//#define �����̃A�j���[�V����2

#ifdef �P�̃A�j���[�V����
#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"ANIM.h"
void gmain() {
    window(1920,1080, full);
    hideCursor();

    ANIM* anim = new ANIM("assets\\bat\\0");
    struct ANIM_DATA animData;
    animData.interval = 0.1f;

    initDeltaTime();
    while (notQuit) {
        setDeltaTime();

        clear(200, 100, 100);
        rectMode(CENTER);
        float px = width / 2;
        float py = height / 2;
        float angle = 0;
        float scale = 8;
        anim->draw(&animData, px, py, angle, scale);
    }

    delete anim;
}
#endif

#ifdef ���[�v���Ȃ��P�̃A�j���[�V����
#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"rand.h"
#include"ANIM.h"
void gmain() {
    window(1920,1080, full);
    hideCursor();

    ANIM* anim = new ANIM("assets\\explosion\\0");
    anim->noLoop();
    struct ANIM_DATA animData;
    animData.interval = 0.032f;

    initDeltaTime();
    while (notQuit) {
        setDeltaTime();

        if (isTrigger(KEY_SPACE)) {
            animData.reset();
        }
        clear(60, 120, 240);
        rectMode(CENTER);

        float px = width / 2;
        float py = height / 2;
        float angle = 0;
        float scale = 8;
        anim->draw(&animData, px, py, angle, scale);
    }
    
    delete anim;
}
#endif

#ifdef �����̃A�j���[�V����
#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"ANIMS.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();

    //�q�t�H���_�ɂ͓������Ƃ̉摜�𕪗ނ��Ă���
    //�e�t�H���_�����w�肷��Ǝ����I�ɓ������Ƃ̉摜�����[�h�����
    ANIMS* anims = new ANIMS("assets\\pumpkin");
    struct ANIM_DATA animData;
    animData.interval = 0.1f;
    int animIdx = 0;

    initDeltaTime();
    while (notQuit) {
        setDeltaTime();

        bool inputFlag = false;
        if (isPress(KEY_D)) { animIdx = 0; inputFlag = true; }
        if (isPress(KEY_A)) { animIdx = 1; inputFlag = true; }
        if (inputFlag == false) {
            animData.reset();
        }

        clear(60, 180, 60);
        rectMode(CENTER);
        float px = width / 2;
        float py = height / 2;
        float angle = 0;
        float scale = 8;
        anims->anim(animIdx)->draw(&animData, px, py, angle, scale);
    }

    delete anims;
}
#endif

#ifdef �����̃A�j���[�V����2
#include"framework.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"ANIMS.h"
void gmain() {
    window(1920,1080, full);
    hideCursor();

    ANIMS* anims = new ANIMS("assets\\funa.png", 4, 4, 40, 64);
    struct ANIM_DATA animData;
    animData.interval = 0.1f;
    int animIdx = 0;

    initDeltaTime();
    while (notQuit) {
        setDeltaTime();

        bool inputFlag = false;
        if (isPress(KEY_D)) { animIdx = 2; inputFlag = true; }
        if (isPress(KEY_A)) { animIdx = 1; inputFlag = true; }
        if (isPress(KEY_S)) { animIdx = 0; inputFlag = true; }
        if (isPress(KEY_W)) { animIdx = 3; inputFlag = true; }
        if (inputFlag == false) {
            animData.reset();
        }

        clear(60, 180, 60);
        rectMode(CENTER);
        float px = width / 2;
        float py = height / 2;
        float angle = 0;
        float scale = 8;
        anims->anim(animIdx)->draw(&animData, px, py, angle, scale);
    }

    delete anims;
}
#endif