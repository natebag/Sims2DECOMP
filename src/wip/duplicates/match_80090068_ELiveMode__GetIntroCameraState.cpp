// 0x80090068 (8 bytes)
class ELiveMode {
public:
    int GetIntroCameraState();
};

int ELiveMode::GetIntroCameraState() {
    return *(int*)((char*)this + 0xC);
}
