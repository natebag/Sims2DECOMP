// 0x8003536C (8 bytes)
class ESim {
public:
    int GetIsModelLoaded();
};

int ESim::GetIsModelLoaded() {
    return *(int*)((char*)this + 0x638);
}
