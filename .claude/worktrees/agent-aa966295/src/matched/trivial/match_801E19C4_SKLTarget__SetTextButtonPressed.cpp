// 0x801E19C4 (8 bytes)
class SKLTarget {
public:
    void SetTextButtonPressed(int p);
};

void SKLTarget::SetTextButtonPressed(int p) {
    *(int*)((char*)this + 0x9C) = p;
}
