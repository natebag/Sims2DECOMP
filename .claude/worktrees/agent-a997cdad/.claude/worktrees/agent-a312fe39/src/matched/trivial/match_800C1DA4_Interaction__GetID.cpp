// 0x800C1DA4 (8 bytes)
class Interaction {
public:
    int GetID();
};

int Interaction::GetID() {
    return *(int*)((char*)this + 0x38);
}
