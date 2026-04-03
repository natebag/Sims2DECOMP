// 0x800C1FF8 (8 bytes)
class Interaction {
public:
    void SetFlags(int p);
};

void Interaction::SetFlags(int p) {
    *(int*)((char*)this + 0x3C) = p;
}
