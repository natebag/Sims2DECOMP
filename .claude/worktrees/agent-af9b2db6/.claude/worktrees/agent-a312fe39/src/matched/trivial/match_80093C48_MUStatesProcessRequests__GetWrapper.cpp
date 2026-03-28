// 0x80093C48 (8 bytes)
class MUStatesProcessRequests {
public:
    int GetWrapper();
};

int MUStatesProcessRequests::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
