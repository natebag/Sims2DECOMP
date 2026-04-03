// 0x800C1DAC (8 bytes)
class Interaction {
public:
    void SetID(int p);
};

void Interaction::SetID(int p) {
    *(int*)((char*)this + 0x38) = p;
}
