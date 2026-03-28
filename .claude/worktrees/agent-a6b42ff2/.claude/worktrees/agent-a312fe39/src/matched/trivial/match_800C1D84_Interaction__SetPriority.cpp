// 0x800C1D84 (8 bytes)
class Interaction {
public:
    void SetPriority(int p);
};

void Interaction::SetPriority(int p) {
    *(int*)((char*)this + 0x28) = p;
}
