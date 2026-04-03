// 0x80021930 (8 bytes)
class ECheatDMI {
public:
    int GetType();
};

int ECheatDMI::GetType() {
    return *(int*)((char*)(*(int*)((char*)this + 0xC)) + 0x4C);
}
