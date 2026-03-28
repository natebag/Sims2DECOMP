// 0x8002193C (8 bytes)
class ECheatDMI {
public:
    int GetVariable();
};

int ECheatDMI::GetVariable() {
    return *(int*)((char*)(*(int*)((char*)this + 0xC)) + 0x50);
}
