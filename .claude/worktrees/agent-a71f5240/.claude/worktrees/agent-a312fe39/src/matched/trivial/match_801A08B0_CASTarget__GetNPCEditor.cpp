// 0x801A08B0 (8 bytes)
class CASTarget {
public:
    int GetNPCEditor();
};

int CASTarget::GetNPCEditor() {
    return *(int*)((char*)this + 0x1354);
}
