// 0x802E38DC (8 bytes)
class EEngine {
public:
    int CanReset();
};

int EEngine::CanReset() {
    return *(int*)((char*)this + 0xC);
}
