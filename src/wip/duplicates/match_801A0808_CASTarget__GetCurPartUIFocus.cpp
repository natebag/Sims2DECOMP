// 0x801A0808 (8 bytes)
class CASTarget {
public:
    int GetCurPartUIFocus();
};

int CASTarget::GetCurPartUIFocus() {
    return *(int*)((char*)this + 0xA4);
}
