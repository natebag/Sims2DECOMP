// 0x80094108 (8 bytes)
class MUStatesTransitionAutoSaveExisting {
public:
    int GetWrapper();
};

int MUStatesTransitionAutoSaveExisting::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
