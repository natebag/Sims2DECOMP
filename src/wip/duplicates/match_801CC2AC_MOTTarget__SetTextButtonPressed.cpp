// 0x801CC2AC (8 bytes)
class MOTTarget {
public:
    void SetTextButtonPressed(int p);
};

void MOTTarget::SetTextButtonPressed(int p) {
    *(int*)((char*)this + 0x94) = p;
}
