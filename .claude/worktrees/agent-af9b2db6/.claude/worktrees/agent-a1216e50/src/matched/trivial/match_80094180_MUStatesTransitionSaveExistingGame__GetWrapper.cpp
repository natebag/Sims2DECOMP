// 0x80094180 (8 bytes)
class MUStatesTransitionSaveExistingGame {
public:
    int GetWrapper();
};

int MUStatesTransitionSaveExistingGame::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
