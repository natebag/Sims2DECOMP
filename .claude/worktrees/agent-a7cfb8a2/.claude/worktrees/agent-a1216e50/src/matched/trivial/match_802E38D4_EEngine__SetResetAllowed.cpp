// 0x802E38D4 (8 bytes)
class EEngine {
public:
    void SetResetAllowed(int p);
};

void EEngine::SetResetAllowed(int p) {
    *(int*)((char*)this + 0xC) = p;
}
