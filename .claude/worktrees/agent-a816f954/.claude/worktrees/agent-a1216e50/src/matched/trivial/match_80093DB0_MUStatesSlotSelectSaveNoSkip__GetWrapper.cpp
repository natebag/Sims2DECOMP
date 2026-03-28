// 0x80093DB0 (8 bytes)
class MUStatesSlotSelectSaveNoSkip {
public:
    int GetWrapper();
};

int MUStatesSlotSelectSaveNoSkip::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
