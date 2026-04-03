// 0x801A0800 (8 bytes)
class CASTarget {
public:
    int GetPrevUIFocus();
};

int CASTarget::GetPrevUIFocus() {
    return *(int*)((char*)this + 0xA0);
}
