// 0x80093F18 (8 bytes)
class MUStatesAutoSaveNew {
public:
    int GetWrapper();
};

int MUStatesAutoSaveNew::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
