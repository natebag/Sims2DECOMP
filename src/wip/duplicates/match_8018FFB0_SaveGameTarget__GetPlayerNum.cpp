// 0x8018FFB0 (8 bytes)
class SaveGameTarget {
public:
    int GetPlayerNum();
};

int SaveGameTarget::GetPlayerNum() {
    return *(int*)((char*)(*(int*)((char*)this + 0x118)) + 0x190);
}
