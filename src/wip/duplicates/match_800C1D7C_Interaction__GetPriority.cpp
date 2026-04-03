// 0x800C1D7C (8 bytes)
class Interaction {
public:
    int GetPriority();
};

int Interaction::GetPriority() {
    return *(int*)((char*)this + 0x28);
}
