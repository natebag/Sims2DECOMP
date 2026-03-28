// 0x80093FA0 (8 bytes)
class MUStatesSaveNewGame {
public:
    int GetWrapper();
};

int MUStatesSaveNewGame::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
