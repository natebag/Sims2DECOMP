// 0x802E38C4 (8 bytes)
class EEngine {
public:
    void SetCurrentLevel(int p);
};

void EEngine::SetCurrentLevel(int p) {
    *(int*)((char*)this + 0x30) = p;
}
