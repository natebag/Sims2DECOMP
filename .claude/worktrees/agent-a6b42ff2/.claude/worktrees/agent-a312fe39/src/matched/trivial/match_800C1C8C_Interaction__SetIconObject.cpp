// 0x800C1C8C (8 bytes)
class Interaction {
public:
    void SetIconObject(int p);
};

void Interaction::SetIconObject(int p) {
    *(int*)((char*)this + 0x10) = p;
}
