// 0x8003FA24 (8 bytes)
class EGlobal {
public:
    void SetCameraDirector(int p);
};

void EGlobal::SetCameraDirector(int p) {
    *(int*)((char*)this + 0xE0) = p;
}
