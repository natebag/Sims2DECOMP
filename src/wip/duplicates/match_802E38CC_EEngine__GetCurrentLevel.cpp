// 0x802E38CC (8 bytes)
class EEngine {
public:
    int GetCurrentLevel();
};

int EEngine::GetCurrentLevel() {
    return *(int*)((char*)this + 0x30);
}
