// 0x8018CCE8 (8 bytes)
class LoadGameTarget {
public:
    int GetPlayerNum();
};

int LoadGameTarget::GetPlayerNum() {
    return *(int*)((char*)(*(int*)((char*)this + 0x118)) + 0x190);
}
