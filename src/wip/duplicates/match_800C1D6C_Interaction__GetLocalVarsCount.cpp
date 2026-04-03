// 0x800C1D6C (8 bytes)
class Interaction {
public:
    int GetLocalVarsCount();
};

int Interaction::GetLocalVarsCount() {
    return *(int*)((char*)this + 0x20);
}
