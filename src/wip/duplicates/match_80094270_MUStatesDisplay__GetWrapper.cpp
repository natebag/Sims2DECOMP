// 0x80094270 (8 bytes)
class MUStatesDisplay {
public:
    int GetWrapper();
};

int MUStatesDisplay::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
