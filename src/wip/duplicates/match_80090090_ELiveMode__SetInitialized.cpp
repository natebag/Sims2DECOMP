// 0x80090090 (8 bytes)
class ELiveMode {
public:
    void SetInitialized(int p);
};

void ELiveMode::SetInitialized(int p) {
    *(int*)((char*)this + 0x30) = p;
}
