// 0x8003FA1C (8 bytes)
class EGlobal {
public:
    int GetCam();
};

int EGlobal::GetCam() {
    return *(int*)((char*)this + 0xD0);
}
