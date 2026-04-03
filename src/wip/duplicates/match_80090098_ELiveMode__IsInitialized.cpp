// 0x80090098 (8 bytes)
class ELiveMode {
public:
    int IsInitialized();
};

int ELiveMode::IsInitialized() {
    return *(int*)((char*)this + 0x30);
}
