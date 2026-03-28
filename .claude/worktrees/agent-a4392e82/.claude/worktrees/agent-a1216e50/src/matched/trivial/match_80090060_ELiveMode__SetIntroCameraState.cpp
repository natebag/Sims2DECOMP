// 0x80090060 (8 bytes)
class ELiveMode {
public:
    void SetIntroCameraState(int p);
};

void ELiveMode::SetIntroCameraState(int p) {
    *(int*)((char*)this + 0xC) = p;
}
