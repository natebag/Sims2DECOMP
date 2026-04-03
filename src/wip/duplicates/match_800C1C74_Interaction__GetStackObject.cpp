// 0x800C1C74 (8 bytes)
class Interaction {
public:
    int GetStackObject();
};

int Interaction::GetStackObject() {
    return *(int*)((char*)this + 0xC);
}
