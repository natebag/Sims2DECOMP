// 0x80093EA0 (8 bytes)
class MUStatesLoadHouse {
public:
    int GetWrapper();
};

int MUStatesLoadHouse::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
