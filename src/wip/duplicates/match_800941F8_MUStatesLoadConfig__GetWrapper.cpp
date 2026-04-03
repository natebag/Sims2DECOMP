// 0x800941F8 (8 bytes)
class MUStatesLoadConfig {
public:
    int GetWrapper();
};

int MUStatesLoadConfig::GetWrapper() {
    return *(int*)((char*)(*(int*)((char*)this + 0x8)) + 0x98);
}
