// 0x8003FA14 (8 bytes)
class EGlobal {
public:
    void SetCam(int p);
};

void EGlobal::SetCam(int p) {
    *(int*)((char*)this + 0xD0) = p;
}
