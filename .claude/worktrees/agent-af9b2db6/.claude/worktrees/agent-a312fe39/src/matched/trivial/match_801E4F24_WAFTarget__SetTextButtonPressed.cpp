// 0x801E4F24 (8 bytes)
class WAFTarget {
public:
    void SetTextButtonPressed(int p);
};

void WAFTarget::SetTextButtonPressed(int p) {
    *(int*)((char*)this + 0x9C) = p;
}
