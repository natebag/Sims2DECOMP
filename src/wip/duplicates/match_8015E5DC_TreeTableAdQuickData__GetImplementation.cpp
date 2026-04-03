// 0x8015E5DC (8 bytes)
class TreeTableAdQuickData {
public:
    int GetImplementation();
};

int TreeTableAdQuickData::GetImplementation() {
    return *(int*)((char*)this + 0x4);
}
