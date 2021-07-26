#pragma once
struct ANIM_DATA {
    int imgIdx = 0;
    float elapsedTime = 0;
    float interval = 0.1f;
    void reset() { imgIdx = 0; elapsedTime = 0; }
};
class ANIM {
private:
    int NumImgs = 0;
    int* Imgs = 0;
public:
    ANIM();
    //ANIM(int numImgs, const char* bodyName, float interval);
    //ANIM(const char* filename, int cols, int rows, int w, int h);
    ANIM(const char* pathName);
    ~ANIM();
    void load(const char* pathName);
    void draw(ANIM_DATA* data, float px, float py);
    void drawOnce(ANIM_DATA* data, float px, float py);
    bool end(const ANIM_DATA& data) { return data.imgIdx >= NumImgs; }
};

