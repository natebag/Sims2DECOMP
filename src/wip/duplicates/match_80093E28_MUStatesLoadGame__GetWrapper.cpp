// 0x80093E28 (8 bytes)
class MUStatesLoadGame {
public:
    int GetWrapper();
};

int MUStatesLoadGame::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
