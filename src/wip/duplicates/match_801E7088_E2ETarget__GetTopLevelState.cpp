// 0x801E7088 (8 bytes)
class E2ETarget {
public:
    int GetTopLevelState();
};

int E2ETarget::GetTopLevelState() {
    return *(int*)((char*)this + 0xD8);
}
