// 0x8015E8A4 (8 bytes)
class TreeTableEntryQuickData {
public:
    int GetImplementation();
};

int TreeTableEntryQuickData::GetImplementation() {
    return *(int*)((char*)this + 0x4);
}
