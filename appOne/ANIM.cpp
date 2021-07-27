#include"window.h"
#include"graphic.h"
#include<filesystem>
#include"ANIM.h"
ANIM::ANIM() {
}
/*
//êßçÏíÜ
ANIM::ANIM(int numImgs, const char* bodyName, float interval) {
    NumImgs = numImgs;
    Imgs = new int[NumImgs];
    char name[64];
    for (int i = 0; i < numImgs; i++) {
        sprintf_s(name, "%s%02d.png", bodyName, i);
        Imgs[i] = loadImage(name);
    }
    Interval = interval;
    StartIdx = 0;
    EndIdx = NumImgs;
}
ANIM::ANIM(const char* fileName, int cols, int rows, int w, int h) {
    NumImgs = cols * rows;
    Imgs = new int[NumImgs];
    int img = loadImage(fileName);
    divideImage(img, cols, rows, w, h, Imgs);
    Interval = 0.1f;
    StartIdx = 0;
    EndIdx = NumImgs;
}
*/
ANIM::ANIM(const char* pathName){
    load(pathName);
}
ANIM::~ANIM() {
    delete[] Imgs;
}
void ANIM::load(const char* path) {
    namespace fs = std::filesystem;
    NumImgs = 0;
    for (const auto& e : fs::directory_iterator(path)) {
        NumImgs++;
    }
    Imgs = new int[NumImgs];
    int i = 0;
    for (const auto& e : fs::directory_iterator(path)) {
        Imgs[i] = loadImage(e.path().string().c_str());
        i++;
    }
}
void ANIM::draw(ANIM_DATA* data, float px, float py){
    data->elapsedTime += delta;
    if (data->elapsedTime >= data->interval) {
        data->elapsedTime -= data->interval;
        ++(data->imgIdx);
        if (data->imgIdx >= NumImgs) {
            data->imgIdx = 0;
        }
    }
    image(Imgs[data->imgIdx], px, py);
}
void ANIM::drawOnce(ANIM_DATA* data, float px, float py) {
    if (data->imgIdx >= NumImgs) {
        return;
    }
    data->elapsedTime += delta;
    if (data->elapsedTime >= data->interval) {
        data->elapsedTime -= data->interval;
        ++(data->imgIdx);
    }
    if (data->imgIdx < NumImgs) {
        image(Imgs[data->imgIdx], px, py);
    }
}

