// 0x8015E7C8 (8 bytes)
class TreeTableEntryQuickData {
public:
    int GetFlags();
};

int TreeTableEntryQuickData::GetFlags() {
    return *(int*)((char*)(*(int*)((char*)this + 0x4)) + 0x10);
}
