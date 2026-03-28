// 0x80094090 (8 bytes)
class MUStatesSaveExistingGame {
public:
    int GetWrapper();
};

int MUStatesSaveExistingGame::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
