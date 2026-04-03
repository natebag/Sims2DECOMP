// 0x800C1D74 (8 bytes)
class Interaction {
public:
    int GetTreeTabEntryIndex();
};

int Interaction::GetTreeTabEntryIndex() {
    return *(int*)((char*)this + 0x14);
}
