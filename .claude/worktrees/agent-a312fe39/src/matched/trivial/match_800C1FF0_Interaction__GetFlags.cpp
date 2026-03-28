// 0x800C1FF0 (8 bytes)
class Interaction {
public:
    int GetFlags();
};

int Interaction::GetFlags() {
    return *(int*)((char*)this + 0x3C);
}
