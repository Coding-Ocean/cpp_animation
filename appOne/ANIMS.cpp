#include"window.h"
#include<filesystem>
#include "ANIMS.h"
ANIMS::ANIMS() {
}
ANIMS::ANIMS(const char* path){
    load(path);
}
ANIMS::~ANIMS() {
    for (int i = 0; i < NumAnims; i++) {
        delete Anims[i];
    }
    delete[] Anims;
}
void ANIMS::load(const char* path){
    namespace fs = std::filesystem;
    NumAnims = 0;
    for (const auto& e : fs::directory_iterator(path)) {
        NumAnims++;
    }
    Anims = new ANIM*[NumAnims];
    int i = 0;
    for (const auto& e : fs::directory_iterator(path)) {
        Anims[i] = new ANIM;
        Anims[i]->load(e.path().string().c_str());
        i++;
    }
}
