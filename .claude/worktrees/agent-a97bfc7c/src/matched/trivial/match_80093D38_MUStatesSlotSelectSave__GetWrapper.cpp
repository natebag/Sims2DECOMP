// 0x80093D38 (8 bytes)
class MUStatesSlotSelectSave {
public:
    int GetWrapper();
};

int MUStatesSlotSelectSave::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
