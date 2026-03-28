// 0x80094018 (8 bytes)
class MUStatesAutoSaveExisting {
public:
    int GetWrapper();
};

int MUStatesAutoSaveExisting::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
