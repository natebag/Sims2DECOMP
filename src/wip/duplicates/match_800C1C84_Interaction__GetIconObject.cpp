// 0x800C1C84 (8 bytes)
class Interaction {
public:
    int GetIconObject();
};

int Interaction::GetIconObject() {
    return *(int*)((char*)this + 0x10);
}
