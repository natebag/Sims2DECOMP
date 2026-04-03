// 0x80093CC0 (8 bytes)
class MUStatesFormat {
public:
    int GetWrapper();
};

int MUStatesFormat::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
