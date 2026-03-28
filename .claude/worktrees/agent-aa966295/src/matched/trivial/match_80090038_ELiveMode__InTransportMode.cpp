// 0x80090038 (8 bytes)
class ELiveMode {
public:
    int InTransportMode();
};

int ELiveMode::InTransportMode() {
    return *(int*)((char*)this + 0x28);
}
