// 0x8015E9A0 (8 bytes)
class TreeTableQuickData {
public:
    int GetImplementation();
};

int TreeTableQuickData::GetImplementation() {
    return *(int*)((char*)this + 0x4);
}
