// 0x801CAAB4 (8 bytes)
class MODTarget {
public:
    void SetTextButtonPressed(int p);
};

void MODTarget::SetTextButtonPressed(int p) {
    *(int*)((char*)this + 0xF8) = p;
}
